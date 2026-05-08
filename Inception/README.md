_This project has been created as part of the 42 curriculum by edugonza._

---

# Inception

## Description

The goal of Inception is to teach containerization by building a small but real web infrastructure from scratch using Docker and Docker Compose.

Instead of running all services on a single machine — where one failure can cascade into others — each service runs in its own isolated container. Containers communicate over a private Docker network, share data through named volumes, and are configured through environment variables and secrets. If one service crashes, it doesn't affect the others. If something breaks, the problem is isolated to one container.

The mandatory infrastructure consists of three containers:

- **MariaDB** — database storage
- **WordPress + php-fpm** — application backend
- **NGINX** — the only entry point, handles HTTPS and routes requests

The request flow is:

```
Browser
  ↓ HTTPS port 443
NGINX
  ├── serves static files directly from /var/www/html
  └── forwards PHP requests → wordpress:9000
        ↓
WordPress (php-fpm)
  ├── executes PHP files from /var/www/html
  └── reads/writes → mariadb:3306
        ↓
MariaDB
  └── persists data in /var/lib/mysql
```

Two containers share one volume (`/var/www/html`): both NGINX and WordPress need to read WordPress files from the same location.

MaariaDB will have a separated volume to persist memory exclusively for the DataBase.

In a bit more details, each container:

MariaDB container
- Installs: mariadb-server
- Entrypoint: initializes DB, creates user and database, starts mysqld

WordPress container
- Installs: php-fpm + PHP extensions WordPress needs + wget + mariadb-client
- Entrypoint:
	a. Downloads WordPress zip from wordpress.org into /var/www/html
	b. Creates wp-config.php with DB credentials
	c. Runs WP-CLI to finish installation (creates admin user, sets site title)
	d. Starts php-fpm -F
- The /var/www/html folder is a volume — you create it, you populate it

Nginx container
- Installs: nginx
- Config file tells it: listen on 443, use SSL, serve files from /var/www/html, forward .php to wordpress:9000
- Entrypoint: just starts nginx

---

## Instructions

### Prerequisites

Docker and Docker Compose must be installed. To install Docker on a fresh Debian/Ubuntu system:

```bash
# Remove any old installations
sudo apt-get remove -y docker docker.io docker-compose docker-compose-v2 podman-docker containerd runc
sudo apt-get purge -y docker docker.io docker-compose
sudo apt-get autoremove -y

# Install Docker from the official repo
sudo apt-get update
sudo apt-get install -y ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

CODENAME=$(. /etc/os-release && echo "$VERSION_CODENAME")
echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] \
https://download.docker.com/linux/ubuntu $CODENAME stable" | \
sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update
sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# Add your user to the docker group
sudo usermod -aG docker $USER
newgrp docker
```

Verify the installation:
```bash
docker --version
docker compose version
```

---

### Setup

**Step 1 — Create the secrets folder:**
```bash
mkdir secrets
echo "your_db_password"       > secrets/db_password.txt
echo "your_root_password"     > secrets/db_root_password.txt
echo "your_admin_db_password" > secrets/db_admin_password.txt
echo "your_wp_admin_password" > secrets/wp_admin_password.txt
echo "your_wp_user_password"  > secrets/wp_user_password.txt
```

**Step 2 — Configure the environment:**

Edit `srcs/.env` with your values. The domain name, database name, WordPress usernames, and ports are all set here. Passwords are read from the secrets folder — never put them in `.env`.

**Step 3 — Add the domain to `/etc/hosts`:**
```bash
echo "127.0.0.1    localhost" | sudo tee -a /etc/hosts
```

---

### Running

```bash
make          # build and start mandatory services
make bonus    # build and start all services including bonus
make stop     # stop containers without removing them
make clean    # stop and remove containers
make fclean   # stop containers, remove images, wipe all data
make re       # clean restart, data preserved
make re_f     # full reset, data wiped
```

For a complete list of available commands:
```bash
make help
```

---

### Verification

After `make`, verify the stack is healthy:

```bash
# All containers running
docker compose -f srcs/docker-compose.yml ps

# WordPress installed correctly
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp core is-installed --path=/var/www/html --allow-root

# MariaDB has the correct users and database
docker compose -f srcs/docker-compose.yml exec mariadb \
    mariadb -u root -p$(cat secrets/db_root_password.txt) \
    -e "SHOW DATABASES; SELECT user, host FROM mysql.user;"
```

Then open `https://localhost` in your browser. Accept the self-signed certificate warning — the connection is still encrypted.

---

## Project description

### Design choices

Each container has a single responsibility. No container installs more than it needs. No service is accessible except through NGINX on port 443. Passwords are never hardcoded — they're read from Docker secrets at runtime and never appear in any file tracked by git.

The entrypoint pattern used in every container follows the same structure:
1. Read secrets and environment variables
2. Wait for dependencies to be ready (connection polling, not sleep)
3. Initialize state on first run only (idempotent check)
4. Apply any runtime configuration (port substitution via sed)
5. `exec` the main process as PID 1

---

### Virtual Machines vs Docker

A virtual machine emulates an entire computer — it has its own kernel, its own OS, its own hardware abstraction layer. It's slow to start, heavy on resources, and completely isolated. You can run Windows inside a Linux VM.

Docker containers share the host kernel. There's no hardware emulation. A container is just a process running with an isolated filesystem, network, and process namespace. It starts in milliseconds, uses far less memory, and runs only what it needs.

The trade-off: VMs offer stronger isolation (separate kernel), containers offer lighter weight and faster startup. For running multiple services on the same machine that trust each other, containers are the right tool.

---

### Secrets vs Environment Variables

Environment variables are visible to anyone who can run `docker inspect` on a container. They appear in process listings, get logged accidentally, and can be read by any process inside the container.

Docker secrets are mounted as files inside `/run/secrets/` inside the container. They're never stored in the image, never visible in inspect output, and are only accessible to the process that needs them. The entrypoint reads the file once and stores the value in a shell variable — the secret file itself is never exposed further.

For this project: non-sensitive configuration (domain name, usernames, ports) lives in `.env`. Passwords live in `secrets/`.

---

### Docker Network vs Host Network

`network: host` makes a container share the host machine's network stack entirely. The container has no network isolation — it can see all host interfaces, bind to any port, and communicate with any service on the host. It's fast but eliminates a key security boundary.

A Docker bridge network creates a private internal network. Containers on the same network can reach each other by service name (Docker's internal DNS resolves `mariadb` to the MariaDB container's IP). Nothing outside the network can reach them directly. NGINX is the only container with a port mapped to the host (`443:443`) — everything else is internal only.

For this project, `network: host` is explicitly forbidden. All inter-container communication goes through the `inception` bridge network.

---

### Docker Volumes vs Bind Mounts

A bind mount directly maps a host directory into a container: `/home/user/data:/var/lib/mysql`. The host path must exist, and the host filesystem structure is exposed to the container. If the host path changes, the container breaks.

A named volume is managed by Docker. Docker creates and tracks the storage location. You reference it by name (`vol-mariadb`), not by path. The subject requires named volumes but also requires them to store data at a specific host path (`/home/#{USER}/data/`) — this is achieved with `driver_opts` in the compose file, giving you named volume semantics with a controlled host location.

The benefit: named volumes survive `docker compose down` and can be inspected with `docker volume inspect`.

---

## Resources

- [Debian releases](https://www.debian.org/releases/)
- [WordPress installation requirements](https://wordpress.org/about/requirements/)
- [WP-CLI command reference](https://developer.wordpress.org/cli/commands/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [MariaDB documentation](https://mariadb.com/kb/en/)
- [Docker Compose reference](https://docs.docker.com/compose/compose-file/)
- [nginx "if is evil"](https://nginx-wiki.getpagespeed.com/config/if-is-evil/)
- [Markdown syntax guide](https://www.markdownguide.org/basic-syntax/)

### AI usage

Claude (claude.ai) was the primary AI tool used throughout this project, functioning as an interactive tutor rather than a code generator. The approach was to use AI to explain concepts and guide reasoning — not to produce code that gets copy-pasted without understanding.

Specifically, AI was used for:

- **Conceptual explanations** — understanding how TLS handshakes work, why php-fpm needs to bind to `0.0.0.0`, what PID 1 means in a container context, the difference between TCP ports and Unix sockets, how nginx location block priority works
- **Debugging guidance** — interpreting error messages from container logs, identifying why nginx was generating wrong redirect URLs when the internal port changed, tracing why WordPress URLs broke after a port change
- **Design decisions** — reasoning through the Dockerfile vs entrypoint split, understanding why `tail -f` is prohibited, evaluating approaches for serving a static landing page alongside WordPress
- **Code review** — identifying issues in entrypoint scripts such as incorrect `set -e` interaction with wp-cli commands, sed patterns that silently failed, and race conditions in service startup ordering

All AI-generated explanations were verified by testing, reading official documentation, and peer discussion. No code was used without understanding it line by line.
