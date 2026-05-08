# User Documentation — Inception

## What is this project?

Inception is a containerized web infrastructure running three core services:

- **NGINX** — the only entry point into the infrastructure, handles HTTPS on port 443 and routes requests to the appropriate service
- **WordPress + php-fpm** — the content management system, processes PHP and serves dynamic content
- **MariaDB** — the database that stores all WordPress content, users, and settings

All three services run in isolated Docker containers and communicate over a private Docker network. Data is persisted across restarts via named volumes stored on the host machine.

---

## Starting and stopping the project

**Start (mandatory services only):**
```bash
make
```

**Start (with bonus services — Redis, Adminer, Static site):**
```bash
make bonus
```

**Stop containers without removing data:**
```bash
make clean
```

**Stop containers and remove all data (full reset):**
```bash
make fclean
```

**Rebuild everything (mandatory) from scratch:**
```bash
make re_f
```

**For any doubts:**
```bash
make help
```

---

## Accessing the website

Add the following line to your `/etc/hosts` file on the host machine:
```
<vm_ip_address>    <your-login>.42.fr
```
> vm_ip_address - for a local server is 127.0.0.1
> your-login - can be any word you prefer. For this project we had to put our own login

Then open your browser and visit:
```
https://<your-login>.42.fr
```

You will see a certificate warning because the SSL certificate is self-signed. Click through it — the connection is still encrypted.

**The site is only accessible via HTTPS (port 443).** Accessing via HTTP (port 80) will not work — this is intentional.

---

## Accessing the WordPress administration panel

Visit:
```
https://<your-login>.42.fr/wp-admin
```

Log in with the administrator credentials stored in `secrets/wp_admin_password.txt`. The administrator username is defined in `srcs/.env` under `WP_ADMIN_USER`.

> The administrator username must not contain "admin" or "administrator" — this is a project requirement.

---

## Managing credentials

All sensitive credentials are stored in the `secrets/` folder at the root of the repository. This folder is never committed to git.

| File | Purpose |
|------|---------|
| `secrets/db_password.txt` | WordPress database user password |
| `secrets/db_root_password.txt` | MariaDB root password |
| `secrets/db_admin_password.txt` | MariaDB admin user password |
| `secrets/wp_admin_password.txt` | WordPress administrator password |
| `secrets/wp_user_password.txt` | WordPress regular user password |

Non-sensitive configuration (domain name, usernames, ports) is stored in `srcs/.env`.

---

## Checking that services are running correctly

**Check container status:**
```bash
make status
```

All containers should show `Up` and not `Restarting`.

**Check live logs:**
```bash
make logs
```

**Check a specific service:**
```bash
make logs-nginx
make logs-wordpress
make logs-mariadb
```

**Verify WordPress is installed and connected to the database:**
```bash
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp core is-installed --path=/var/www/html --allow-root
```

No output means success.

---

## Bonus services (when running `make bonus`)

| Service | URL | Purpose |
|---------|-----|---------|
| Static site | `https://<your-login>.42.fr/static/` | Standalone HTML site independent of WordPress |
| Adminer | `https://<your-login>.42.fr/adminer/` | Web-based database management interface |
| Redis | Internal only | Object cache for WordPress performance |

**Accessing Adminer:**
- Visit `https://<your-login>.42.fr/adminer/`
- System: MySQL
- Server: `mariadb`
- Username: value of `DB_USER` in `srcs/.env`
- Password: contents of `secrets/db_password.txt`
- Database: value of `DB_NAME` in `srcs/.env`

---

## Persistence verification

Data is stored in `/home/<your-login>/data/` on the host machine:
- `/home/<your-login>/data/wordpress` — WordPress files and uploads
- `/home/<your-login>/data/mariadb` — database files

After a full VM reboot, run `make` again. All WordPress content, users, and settings will be restored exactly as left.
