# Docker Modules – A Conceptual Guide

> **A note before you read:** This guide was generated through an AI-assisted learning session. It is intended as a conceptual reference — a thinking framework for understanding Docker, not a copy-paste solution. The goal is for you to understand *why* things work the way they do, so that when something breaks, you know where to look.

---

## Module 1 — What is a Container, and Why Does it Exist?

### The problem Docker solves

Imagine you've built a web server and want to run it on another machine. What do you need? The right OS version, the right compiler and libraries, the right config files in the right paths, the right user permissions, maybe a specific version of OpenSSL. If anything is off, it breaks. The classic developer complaint: *"It works on my machine."*

Before Docker, the solution was Virtual Machines (VMs). A VM emulates an entire computer — CPU, RAM, disk, its own OS kernel. It works, but it's heavy:

```
Your physical machine
└── Hypervisor (VMware, VirtualBox...)
    ├── VM 1: full Linux OS (1GB RAM, 10GB disk) → runs your app
    ├── VM 2: full Linux OS (1GB RAM, 10GB disk) → runs another app
    └── VM 3: full Linux OS (1GB RAM, 10GB disk) → runs another app
```

Each VM boots a whole OS. Slow to start, wastes resources.

### The container idea

A container takes a different approach. Instead of virtualizing the hardware, it shares the host OS kernel but isolates everything else — filesystem, processes, network, users.

```
Your physical machine
└── Linux kernel (shared)
    ├── Container 1: isolated filesystem + processes → runs NGINX
    ├── Container 2: isolated filesystem + processes → runs WordPress
    └── Container 3: isolated filesystem + processes → runs MariaDB
```

Each container thinks it's alone on the machine. It has its own filesystem, its own process list (starting at PID 1), its own network interface. But it's not running a separate kernel — it's using yours. The result: containers start in milliseconds, use megabytes instead of gigabytes, and you can run dozens on a laptop.

> **VM vs Container — the clearest distinction:** A VM is a full computer inside a computer. A container is more like a fence around a process — it controls what that process can *see* and *access*, but it's still a native process running on your kernel. There's no translation layer, which is why containers have near-zero performance overhead compared to running the process directly on the host. A VM, by contrast, has overhead on every system call because the hypervisor has to intercept and translate it.

### The key insight: a container is just a process

This is what most people miss at first. A container is not a mini-VM. It's a regular Linux process with two types of kernel restrictions applied:

- **Namespaces** — what the process can *see* (its own PID table, its own network, its own filesystem view)
- **Cgroups** — what the process can *use* (CPU limits, memory limits)

That's it. When you run a container with NGINX inside, the host kernel is running an NGINX process — it just can't see the rest of your system. If you run `ps aux` on the host, you'll see the container's process right there in the list.

A word on memory: the fence analogy covers visibility and access, but not resources. A running container uses real RAM from your host, just like any other process. What "its own memory" means is simply that one process can't read another process's memory — which is standard Linux behavior, not a Docker feature. Docker doesn't add anything special there.

### Images vs containers

This distinction trips everyone up at the start.

- An **image** is a blueprint — a read-only snapshot of a filesystem plus metadata. Think of it like a class definition.
- A **container** is a running instance of that image — like an object created from that class.

You can run ten containers from the same image. Each gets its own writable layer on top, so they don't interfere with each other.

---

## Module 2 — Docker Images and Layers

### What is an image?

An image is a read-only filesystem snapshot plus some metadata (what command to run, what port to expose, etc.). Think of it like a tar archive of a minimal Linux filesystem — `/bin`, `/etc`, `/usr`, and so on — frozen in time. When you start a container from it, Docker unpacks that filesystem and runs your process inside it.

### The layer system

Images are not monolithic blobs. They're built in layers, stacked on top of each other. Each instruction in a Dockerfile creates one layer:

```
Layer 4: COPY my-config.conf /etc/nginx/   ← your config file
Layer 3: RUN apt-get install -y nginx       ← nginx binary + deps added
Layer 2: RUN apt-get update                 ← package list added
Layer 1: FROM debian:bookworm-slim          ← base debian filesystem
```

Each layer only stores the *diff* from the layer below it — just the files that instruction added or changed, not the entire filesystem.

### Why layers matter: caching

When you rebuild an image, Docker checks each layer: *"Did anything change since I last built this? If not, reuse the cached layer."*

So if you change your config file (Layer 4), Docker reuses layers 1–3 from cache and only rebuilds layer 4. Fast. But if you change Layer 2, Docker invalidates everything above it — layers 3 and 4 rebuild too.

This has a direct consequence for how you write Dockerfiles — stable things go first, changing things go last:

```dockerfile
# BAD — changes to your app code invalidate the apt-get cache
FROM debian:bookworm-slim
COPY my-app-code/ /app/        ← if this changes, next line runs again
RUN apt-get install -y nginx   ← slow, reinstalls every time

# GOOD — stable things first, changing things last
FROM debian:bookworm-slim
RUN apt-get install -y nginx   ← cached after first build
COPY my-app-code/ /app/        ← only this layer rebuilds on code changes
```

> **A specific case where combining commands is mandatory:** `apt-get update` and `apt-get install` must always run together in the same `RUN` instruction. If you split them into two lines, Docker might reuse a stale cached `update` layer months later, causing the install to pull outdated or missing packages. For everything else, more lines generally means more cache granularity — split commands that are independently useful to cache, combine commands that must stay in sync.

> **On the apt cache:** after `apt-get install` finishes, the package index (`/var/lib/apt/lists/`) is useless — the packages are already installed. Keeping it just bloats the image. Always clean up with `&& rm -rf /var/lib/apt/lists/*` at the end of your `RUN` block. This is different from Docker's layer cache, which lives on your host and speeds up builds — the apt cache lives *inside* the image itself.

### The writable layer on top

When a container starts, Docker adds one writable layer on top of the read-only image layers. All writes the container makes go there.

```
[writable layer]     ← container writes here (gone when container stops)
─────────────────
[Layer 4] read-only
[Layer 3] read-only
[Layer 2] read-only
[Layer 1] read-only
```

This is why the image never gets modified by running containers, two containers from the same image don't share writes, and when a container stops, its writes are gone — unless you use a volume (Module 5).

### Image naming

Images are identified as `name:tag`. The tag is the version: `debian:bookworm-slim`, `nginx:1.25`, `mariadb:11.2`. Avoid the `latest` tag — it just means "whatever was most recently pushed," and that changes. Pinning to an explicit version makes your build reproducible.

---

## Module 3 — Writing a Dockerfile

A Dockerfile is a plain text file named exactly `Dockerfile` (no extension). It's a list of instructions Docker executes top to bottom to build an image.

### The essential instructions

**`FROM`** — the base image to start from. Every Dockerfile starts here. You're saying: *"start with this existing filesystem snapshot, then add my stuff on top."*

```dockerfile
FROM debian:bookworm-slim
```

**`RUN`** — execute a shell command during the build. This runs during `docker build`, not when the container starts. The result becomes a new layer.

```dockerfile
RUN apt-get update && apt-get install -y nginx && rm -rf /var/lib/apt/lists/*
```

**`COPY`** — copy files from your machine into the image. Source is relative to where your Dockerfile is; destination is inside the image filesystem.

```dockerfile
COPY conf/nginx.conf /etc/nginx/nginx.conf
```

**`EXPOSE`** — document which port the container listens on. This doesn't actually open anything — it's documentation. Real port mapping happens in docker-compose.

```dockerfile
EXPOSE 443
```

**`CMD`** — the command to run when the container starts. Notice the array format — this matters and connects directly to the PID 1 topic in Module 9.

```dockerfile
CMD ["nginx", "-g", "daemon off;"]
```

**`ENTRYPOINT`** — similar to CMD, but used when you have a startup script that does setup before launching the service. More on this in Module 9.

**`ENV`** — set environment variables inside the container, available at runtime.

**`ARG`** — build-time variables, not available at runtime. Useful for passing values during `docker build` that don't need to persist.

### A real example: minimal NGINX container

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    nginx \
    && rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
```

The filesystem inside this container will contain the full Debian base, your copied config, and the nginx binary installed by apt. The process running inside has no idea it's a container.

> **Why `daemon off;`?** Nginx by default daemonizes — it forks a child process, then the parent exits. In a container, Docker watches the process you told it to run (PID 1). When PID 1 exits, Docker considers the container done and stops everything, including the child. `daemon off;` tells nginx to stay in the foreground as PID 1 and never fork. Every service you run in a container needs this treatment — run in the foreground, don't daemonize. The same principle applies to `php-fpm -F` and running mysqld directly.

### The relationship between Dockerfile, image, and container

```
Dockerfile (instructions to build)
    ↓  docker build
Image (frozen blueprint)
    ↓  docker run
Container (running process)
```

One Dockerfile describes one image. One image runs as one container. For a multi-service project, you have one Dockerfile per service — one for NGINX, one for WordPress, one for MariaDB.

---

## Module 4 — Running Containers

In practice you'll use docker-compose to run everything. But understanding the underlying `docker run` flags means you understand exactly what docker-compose is doing under the hood.

### The key flags

**Detached mode (`-d`)** — run in the background.

```sh
docker run -d nginx:1.25
```

**Port mapping (`-p`)** — containers have their own network namespace; their ports are not your host's ports. This bridges them.

```sh
docker run -p 8080:443 nginx:1.25
# format: host_port:container_port
```

**Environment variables (`-e`)** — pass configuration into the container.

```sh
docker run -e DB_PASSWORD=secret mariadb:11.2
```

**Naming (`--name`)** — without this, Docker assigns a random name. On a Docker network, containers reach each other by name, so this matters.

**Interactive mode (`-it`)** — drop into a shell inside the container. Your main debugging tool for inspecting a running container's environment.

```sh
docker exec -it my-container bash
```

Note: `docker exec` opens a shell in an *already running* container without disturbing PID 1. `docker run -it` starts a *new* container interactively. Use exec for debugging; use run -it for throwaway exploration.

**Restart policy (`--restart`)** — how to behave when the container crashes.

| Policy | Behavior |
|--------|----------|
| `no` | Never restart (default) |
| `on-failure` | Restart only on non-zero exit |
| `always` | Always restart, even on clean stop |
| `unless-stopped` | Restart unless manually stopped |

### Useful commands

```sh
docker ps                    # running containers
docker ps -a                 # all containers including stopped
docker images                # images on your machine
docker logs <name>           # stdout/stderr of a container
docker exec -it <name> bash  # open a shell in a running container
docker stop <name>           # graceful stop
docker rm <name>             # delete a stopped container
docker rmi <image>           # delete an image
docker build -t name .       # build image from Dockerfile in current directory
docker inspect <name>        # full configuration of a running container
```

`docker inspect` deserves special mention. Any time something behaves unexpectedly — wrong port, wrong volume, wrong environment variable — `docker inspect` tells you what Docker *actually* set up versus what you *thought* you configured.

---

## Module 5 — Volumes

The writable container layer disappears when the container stops or is removed. For stateless services that's fine. For a database it's a disaster — you'd lose all your data on every restart.

### What a volume is

A volume is a directory that lives outside the container's filesystem, on your host machine's real disk. You mount it into the container at a specific path. The container reads and writes it like a normal directory, but the data actually lives on the host.

```
Host disk: /home/user/data/db/    ← real files here, survive forever
                    ↕ mounted
Container: /var/lib/mysql/         ← MariaDB writes here
```

When the container restarts, the data is still there. When you delete the container entirely and recreate it, the data is still there.

### Two types of volumes

**Bind mount** — you specify the exact host path:

```yaml
volumes:
  - /home/user/data/db:/var/lib/mysql
```

You control exactly where the data lives. Use this when the subject specifies a path.

**Named volume** — Docker manages the location:

```yaml
volumes:
  - db-data:/var/lib/mysql
```

Docker stores it somewhere under `/var/lib/docker/volumes/`. Easier, but less control over the exact path.

### The first-run problem

When a service starts with an empty volume, it needs to initialize. When it restarts with data already there, it must *not* reinitialize — that would wipe everything. The solution is a guard condition in your entrypoint script: check whether the data directory already contains initialized data, and only run setup if it doesn't.

```sh
if [ ! -d "/var/lib/mysql/mysql" ]; then
    # first run — initialize
fi
```

This pattern appears in both MariaDB and WordPress entrypoints.

> **Create host directories before starting containers.** If the host path doesn't exist when Docker tries to bind-mount it, Docker creates it as root, which causes permission errors. Create the directories in your Makefile before calling docker-compose up.

---

## Module 6 — Networking Between Containers

Containers are isolated — they each have their own network namespace. So how do they reach each other?

### Docker networks

A Docker network is a private virtual network that containers join. Containers on the same network can reach each other; containers on different networks cannot. Docker assigns each container an IP on that network, but you never use IPs directly — they can change on restart. Instead, Docker provides automatic DNS resolution by container name.

Inside a shared network, containers reach each other by their service name:

```
nginx    → can reach "wordpress" on port 9000
wordpress → can reach "mariadb" on port 3306
```

This is why naming your containers matters — the name becomes the hostname on the network.

### Port exposure vs port mapping

Two different things that are easy to confuse:

- **`EXPOSE` in Dockerfile** — documentation only. Says "this container listens on this port." Doesn't open anything.
- **`ports:` in docker-compose** — actually maps a host port to a container port. Makes it reachable from outside Docker.

```yaml
nginx:
  ports:
    - "443:443"    # reachable from the internet

wordpress:
  # no ports: — not reachable from outside
  # but nginx can reach it on the internal network

mariadb:
  # no ports: — completely internal
```

This is the security model for a typical web stack:

```
Internet → port 443 → nginx → (internal network) → wordpress → mariadb
```

MariaDB is never reachable from outside. WordPress is never reachable from outside. Only NGINX has a door to the world, and it decides what to let through. This is the same separation-of-concerns pattern you'd recognize from an API → backend → database architecture — from the outside, you only ever talk to the outermost layer.

### How NGINX talks to WordPress

WordPress runs php-fpm, a PHP process manager that listens on port 9000. NGINX doesn't serve PHP itself — it acts as a **reverse proxy**, forwarding PHP requests to php-fpm and returning the response to the browser. The browser never talks directly to WordPress; it thinks it's talking to NGINX the whole time.

```
Browser → NGINX:443 → (if .php) → wordpress:9000 → response → NGINX → browser
```

In your NGINX config this looks like:

```nginx
fastcgi_pass wordpress:9000;
```

`wordpress` resolves to the WordPress container's IP via Docker's internal DNS. This never touches the host network — it's entirely internal.

---

## Module 7 — docker-compose

`docker run` is for understanding and debugging. `docker-compose` is what you'll actually use. Instead of a sequence of imperative shell commands, you declare the desired state of your entire infrastructure in one file, and docker-compose figures out the order to create everything.

### The structure of docker-compose.yml

```yaml
services:
  service-name:
    build:
      context: ./requirements/nginx
      dockerfile: Dockerfile
    container_name: nginx
    restart: unless-stopped
    ports:
      - "443:443"
    volumes:
      - /home/user/data/nginx:/etc/nginx/certs
    networks:
      - inception
    environment:
      SOME_VAR: value
    env_file:
      - .env
    depends_on:
      - wordpress

networks:
  inception:
    driver: bridge

volumes:
  db-data:
```

> **Order doesn't matter in docker-compose.yml.** Unlike C, docker-compose is not executed line by line. It reads the entire file first, builds a complete picture of what you want, then creates everything in the right order. Services can reference networks and volumes declared later in the file; docker-compose resolves them all at parse time.

### Key directives

**`build`** — where to find the Dockerfile. `context` is the build root (COPY paths are relative to it). If your Dockerfile is named `Dockerfile` and lives directly in that directory, the short form works:

```yaml
build: ./requirements/nginx
```

**`depends_on`** — tells docker-compose to start one service before another. Important caveat: it only waits for the *container to start*, not for the service inside to be *ready*. MariaDB takes a few seconds to initialize after its container starts. WordPress might try to connect before MariaDB is ready. The real solution is a retry loop in your entrypoint script — more on that in Module 9.

**`env_file`** — loads all variables from a file into the container's environment. Non-sensitive config lives here.

**`secrets`** — mounts secret files into the container at `/run/secrets/`. Sensitive values like passwords live here, never in env_file. More on this in Module 8.

### Key commands

```sh
docker-compose up -d           # build images if needed, start all containers
docker-compose up --build -d   # force rebuild even if images exist
docker-compose down            # stop and remove containers (volumes survive)
docker-compose down -v         # stop, remove containers AND wipe volumes
docker-compose logs -f         # follow logs from all containers
docker-compose logs nginx      # logs from one service
docker-compose ps              # status of all services
docker-compose exec nginx bash # open shell in running container
docker-compose restart nginx   # restart one service
```

`down` without `-v` is your normal workflow. `down -v` is for a completely clean slate — useful during development when you want to test initialization logic from scratch.

---

## Module 8 — Environment Variables and Secrets

### How variables flow into a container

```
.env file
    ↓ docker-compose reads it
docker-compose.yml substitution  →  ${DB_PASSWORD}
    ↓ passed to container at startup
Container environment
    ↓ read by entrypoint script
Service config / wp-config.php / my.cnf
```

The container's environment is completely separate from the host's. It gets a fresh environment built from whatever you pass via `environment:` or `env_file:`. Nothing leaks in or out automatically.

### ARG vs ENV in a Dockerfile

```dockerfile
ARG  DB_PASSWORD        # exists only during docker build
ENV  DB_PASSWORD=value  # exists at runtime inside the container
```

`ARG` is for build-time only — useful for values needed while building the image, gone after. `ENV` persists into the running container and is what your entrypoint script reads. For this kind of project, you'll mostly use `ENV` and pass values via `env_file` at runtime.

### The problem with ENV for passwords

If you put a password in `ENV`, it's baked into the image layer. Anyone with the image can run `docker inspect` and read all environment variables in plain text. It's also visible in `docker history` and logged by many tools.

### Docker secrets

A secret is a file whose contents are made available to the container at `/run/secrets/<secret_name>`. The contents are never exposed as environment variables and the file lives on a tmpfs mount (RAM, not disk) — it doesn't persist anywhere.

```yaml
# docker-compose.yml
services:
  mariadb:
    secrets:
      - db_password
      - db_root_password

secrets:
  db_password:
    file: ../secrets/db_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
```

In your entrypoint script, read them as files:

```sh
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
```

The password never touches an environment variable.

### The division of responsibility

| Data | Where it lives | How the container gets it |
|------|---------------|--------------------------|
| Hostnames, usernames, DB names | `.env` | ENV variables |
| Passwords | `secrets/*.txt` | `/run/secrets/` files |
| Config files | Dockerfile `COPY` | Baked into image |
| Runtime data | Volumes | Mounted directories |

---

## Module 9 — PID 1 and Process Management

### What PID 1 is

On any Linux system, the first process that starts gets PID 1. On a normal machine that's `init` or `systemd`. In a container, PID 1 is whatever you put in `CMD` or `ENTRYPOINT`. If you write:

```dockerfile
CMD ["nginx", "-g", "daemon off;"]
```

Then nginx is PID 1 inside the container.

### Why PID 1 is special

**Signal handling.** When you run `docker stop`, Docker sends SIGTERM to PID 1, waits 10 seconds, then sends SIGKILL if it's still running. Normally, processes that don't install a custom SIGTERM handler get terminated by the kernel's default action. PID 1 is the exception: the kernel disables default signal actions for PID 1. If PID 1 doesn't explicitly handle SIGTERM, the signal is silently ignored — the process doesn't die. Docker then waits 10 seconds and sends SIGKILL, which cannot be caught or ignored by anything.

Why does the kernel do this? Historical reason: on a real system PID 1 is `init`/`systemd`. If it could be accidentally killed by a stray SIGTERM, the whole system would collapse with no recovery path. So the kernel protects it. In a container, that protection applies to whatever happens to be PID 1 — even nginx, which never asked for it.

Practically: nginx, php-fpm, and mysqld all install their own SIGTERM handlers, so this is fine for your services. But if you put bash as PID 1 and it doesn't handle SIGTERM, `docker stop` hangs for 10 seconds every time.

**Zombie reaping.** When a child process exits, it becomes a zombie until its parent calls `wait()`. On a normal system, if a parent dies, init adopts orphans and reaps their zombies. In a container, if PID 1 doesn't do this, zombies accumulate. For single-process containers this is a non-issue, but it's why proper PID 1 behavior matters in more complex setups.

### The forbidden patterns

```sh
# FORBIDDEN
CMD tail -f /dev/null
CMD sleep infinity
CMD while true; do sleep 1; done
```

These exist as debugging workarounds — a container whose main service isn't working yet, kept alive long enough to exec into. The legitimate version of that is `docker run -it ... bash`, which is clearly intentional and temporary. Shipping a container with a sleep as PID 1 means the actual service isn't running correctly in the foreground — fix that instead.

### The exec pattern

Every entrypoint script should end with `exec`:

```sh
#!/bin/bash

# ... setup work ...

exec mysqld --user=mysql   # replaces the shell with mysqld
```

Without `exec`:
```
PID 1: bash (your script)
  └── PID 2: mysqld (child of bash)
```

Shell is PID 1. SIGTERM goes to bash. Bash might exit, mysqld gets killed without a chance to flush data.

With `exec`:
```
PID 1: mysqld (shell replaced itself)
```

mysqld is PID 1. Docker talks directly to it. Clean shutdown.

### Summary for your three services

| Service | PID 1 | How |
|---------|-------|-----|
| NGINX | nginx process | `CMD ["nginx", "-g", "daemon off;"]` |
| WordPress/php-fpm | php-fpm process | entrypoint ends with `exec php-fpm -F` |
| MariaDB | mysqld process | entrypoint ends with `exec mysqld --user=mysql` |

The `-F` flag on php-fpm means foreground — without it, php-fpm daemonizes, the entrypoint script exits, and the container stops. Same reasoning as `daemon off;` for nginx.

---

## Module 10 — Putting it All Together: The Skeleton

Reading about Docker is like reading about swimming — it only clicks when you get in the water. Here's the complete project skeleton with every file you need, and a note on what each one does. Build one service at a time, bottom up: MariaDB first, then WordPress, then NGINX.

### Directory structure

```
Inception/
├── Makefile
├── secrets/
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   └── conf/
        │       └── nginx.conf
        ├── wordpress/
        │   ├── Dockerfile
        │   └── tools/
        │       └── entrypoint.sh
        └── mariadb/
            ├── Dockerfile
            └── tools/
                └── entrypoint.sh
```

### Makefile

```makefile
DATA_DIR = /home/$(USER)/data

all:
	mkdir -p $(DATA_DIR)/wordpress
	mkdir -p $(DATA_DIR)/mariadb
	docker-compose -f srcs/docker-compose.yml up -d --build

down:
	docker-compose -f srcs/docker-compose.yml down

re: down all

clean: down
	docker-compose -f srcs/docker-compose.yml down -v
	rm -rf $(DATA_DIR)

fclean: clean
	docker system prune -af

.PHONY: all down re clean fclean
```

### secrets/

Three plain text files, one value each:

```
secrets/db_password.txt       → yourdbpassword
secrets/db_root_password.txt  → yourrootpassword
secrets/credentials.txt       → youradminpassword
```

Add to `.gitignore`:
```
secrets/
srcs/.env
```

### srcs/.env

```env
DOMAIN_NAME=your-login.42.fr

DB_NAME=wordpress
DB_USER=wpuser

WP_ADMIN_USER=your-login
WP_ADMIN_EMAIL=your-login@student.42.fr
WP_TITLE=Inception
```

No passwords here — those go in `secrets/`.

### srcs/docker-compose.yml

```yaml
services:

  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    image: mariadb
    restart: unless-stopped
    networks:
      - inception
    volumes:
      - db-data:/var/lib/mysql
    env_file:
      - .env
    secrets:
      - db_password
      - db_root_password

  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    image: wordpress
    restart: unless-stopped
    networks:
      - inception
    volumes:
      - wp-data:/var/www/html
    env_file:
      - .env
    secrets:
      - db_password
      - credentials
    depends_on:
      - mariadb

  nginx:
    build: ./requirements/nginx
    container_name: nginx
    image: nginx
    restart: unless-stopped
    networks:
      - inception
    volumes:
      - wp-data:/var/www/html
    ports:
      - "443:443"
    depends_on:
      - wordpress

networks:
  inception:
    driver: bridge

volumes:
  db-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/mariadb
  wp-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/wordpress

secrets:
  db_password:
    file: ../secrets/db_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
  credentials:
    file: ../secrets/credentials.txt
```

### requirements/mariadb/Dockerfile

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]
```

### requirements/mariadb/tools/entrypoint.sh

```sh
#!/bin/bash
set -e

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --bootstrap << EOF
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${DB_NAME};
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
fi

exec mysqld --user=mysql
```

### requirements/wordpress/Dockerfile

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    php8.2-fpm \
    php8.2-mysql \
    wget \
    && rm -rf /var/lib/apt/lists/*

RUN wget -O /usr/local/bin/wp \
    https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x /usr/local/bin/wp

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]
```

### requirements/wordpress/tools/entrypoint.sh

```sh
#!/bin/bash
set -e

DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/credentials)

until mysqladmin ping -h mariadb -u"${DB_USER}" -p"${DB_PASSWORD}" --silent; do
    echo "Waiting for MariaDB..."
    sleep 2
done

if [ ! -f "/var/www/html/wp-config.php" ]; then

    wp core download --path=/var/www/html --allow-root

    wp config create \
        --path=/var/www/html \
        --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --dbhost=mariadb \
        --allow-root

    wp core install \
        --path=/var/www/html \
        --url="https://${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root

    wp user create student student@student.42.fr \
        --role=author \
        --user_pass=studentpass \
        --path=/var/www/html \
        --allow-root
fi

exec php-fpm8.2 -F
```

### requirements/nginx/Dockerfile

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

RUN openssl req -x509 -nodes -days 365 \
    -subj "/C=DE/ST=Berlin/O=42Berlin/CN=your-login.42.fr" \
    -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
```

### requirements/nginx/conf/nginx.conf

```nginx
events {}

http {
    include /etc/mime.types;

    server {
        listen 443 ssl;
        server_name your-login.42.fr;

        ssl_certificate     /etc/ssl/certs/nginx.crt;
        ssl_certificate_key /etc/ssl/private/nginx.key;
        ssl_protocols       TLSv1.2 TLSv1.3;

        root /var/www/html;
        index index.php;

        location / {
            try_files $uri $uri/ /index.php?$args;
        }

        location ~ \.php$ {
            fastcgi_pass wordpress:9000;
            fastcgi_index index.php;
            include fastcgi_params;
            fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        }
    }
}
```

### Things you will still need to figure out

The skeleton is complete but not production-ready. These are the gaps you'll hit and fix as you build — intentionally left open because debugging them is where the concepts actually land:

- **php-fpm socket vs TCP** — php-fpm may default to a Unix socket. You need it on TCP port 9000 so NGINX can reach it over the Docker network. Configure `/etc/php/8.2/fpm/pool.d/www.conf` with `listen = 0.0.0.0:9000`.
- **MariaDB bind address** — by default MariaDB listens only on localhost. WordPress lives in a different container, so localhost from WordPress's perspective is *not* MariaDB. You'll need to patch the bind address in the MariaDB config to `0.0.0.0`.
- **File permissions** — WordPress files are downloaded during the build as root. php-fpm runs as `www-data`. If `www-data` doesn't own those files, uploads fail and plugins can't be updated. Fix this with `chown -R www-data:www-data` in the entrypoint.
- **SSL certificate CN** — replace `your-login.42.fr` with your actual login everywhere it appears.
- **WordPress admin username** — the subject says the admin username cannot contain "admin". Make sure yours passes that check.

---

*The goal of this guide was never to give you something to copy. It was to give you a mental model solid enough that when something breaks — and things will break — you know which layer to look at.*
