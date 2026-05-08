# Developer Documentation — Inception

## Prerequisites

- A Virtual Machine running Debian or Ubuntu (minimal install)
- Docker and Docker Compose installed
- Git

## SETUP

### If you want a fresh start:

>#### Step 1 — Remove current installation:
>	`sudo apt-get remove -y docker docker.io docker-compose docker-doc docker-compose-v2 podman-docker containerd runc`
>
>	`sudo apt-get purge -y docker docker.io docker-compose`
>
>	`sudo apt-get autoremove -y`
>
>#### Step 2 — Remove leftover data (destructive — this wipes all containers/images/volumes):
>	`sudo rm -rf /var/lib/docker`
>
>	`sudo rm -rf /var/lib/containerd`
>
>	`sudo rm -rf /etc/docker`
>
>#### Step 3 — Add Docker's official repo and install:
>	`sudo apt-get update`
>
>	`sudo apt-get install -y ca-certificates curl`
>
>	`sudo install -m 0755 -d /etc/apt/keyrings`
>
>	`sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc`
>
>	`sudo chmod a+r /etc/apt/keyrings/docker.asc`
>
>	`CODENAME=$(. /etc/os-release && echo "$VERSION_CODENAME")`
>
>	`echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu $CODENAME stable" | sudo
tee /etc/apt/sources.list.d/docker.list > /dev/null`
>
>	`sudo apt-get update`
>
>	`sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin`
>

### After installation or if your current docker installation is working fine:

>#### Step 1 — Add your user to the docker group (so you don't need sudo):
>	`sudo service docker start`
>
>	`sudo usermod -aG docker $USER`
>
>	`newgrp docker`
>
>#### Step 2 — Verify:
>	`docker --version`
>
>	`docker compose version`
>
>	`docker run hello-world`

## RUNNING

> ### ***In case you want to simply fire all containers:***
>
> `make` -> will run all commands necessary to turn on all containers
>
> `make clean` -> will stop the containers
>
> `make fclean` -> will stop the containers and flush the memory
>
> `make help` -> will show all possible commands

> ### ***In case you want to run the commands directly to see the step by step of the results:***
>
> ### To run the implementation:
>	`docker compose -f srcs/docker-compose.yml up --build`
>
> *"-f srcs/docker-compose.yml"* : uses the docker-compose file inside /srcs
>
> *"--build"* : ignores cached images and forces the rebuild of images based on Dockerfiles
>
> ### To stop containers:
>- List containers running
>
>	`docker ps`
>
>- Stop containers using containerID
>
>	`docker stop <containerID>`
>
>
> ### To check DB health status
> - To check general information about the DB (as root):
>
>	`docker exec -it srcs-mariadb-1 mariadb -u root -p`
>
>	`SHOW DATABASES;`
>
>	`SHOW TABLES FROM <database>;`
>
>	`SELECT * FROM <databse>.<table_name>;`
>
> - For example, to check the creation of the user:
>
> 	`SELECT user, host FROM mysql.user;`
>
<!-- > - Additionaly, to test the user configs:
>
> 	`docker exec -it srcs-mariadb-1 mariadb -u <DB_USER> -p <DB_NAME>` -->
> ### To debug containers
> Run a single container in isolation:
> `docker compose -f srcs/docker-compose.yml up --build wordpress`
> (Only builds and runs the wordpress service. You see only its logs.)
>
> Get a shell inside a running container:
> `docker exec -it srcs-wordpress-1 bash`
> (Now you're inside. You can ls, check if files exist, run commands manually, test things interactively before putting them in the entrypoint.)
>
> Run the container with no entrypoint:
> `docker run --rm -it --entrypoint bash srcs-wordpress`
> (Starts the container but skips your entrypoint entirely. You land in a shell and can run each line of your entrypoint manually, one by one, and see exactly which one fails and why.)



## Repository structure

```
.
├── Makefile
├── secrets/                  # Never committed to git
│   ├── db_password.txt
│   ├── db_root_password.txt
│   ├── db_admin_password.txt
│   ├── wp_admin_password.txt
│   └── wp_user_password.txt
└── srcs/
    ├── .env                  # Never committed to git
    ├── docker-compose.yml
    ├── b-docker-compose.yml  # Bonus compose file
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/nginx.conf
        │   └── tools/entrypoint.sh
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── conf/www.conf
        │   └── tools/entrypoint.sh
        ├── mariadb/
        │   ├── Dockerfile
        │   └── tools/entrypoint.sh
        └── bonus/
            ├── redis/Dockerfile
            ├── adminer/Dockerfile
            └── static/
                ├── Dockerfile
                ├── conf/nginx.conf
                └── tools/data/
```

---

## Setting up from scratch

**Step 1: Create the secrets folder and files**
```bash
mkdir secrets
echo "your_db_password" > secrets/db_password.txt
echo "your_root_password" > secrets/db_root_password.txt
echo "your_admin_password" > secrets/db_admin_password.txt
echo "your_wp_admin_password" > secrets/wp_admin_password.txt
echo "your_wp_user_password" > secrets/wp_user_password.txt
```


**Step 2: Configure the environment**

Edit `srcs/.env`:
```dotenv
DOMAIN_NAME=<your-login>.42.fr

# Docker ports
DB_PORT=3306
WP_PORT=9000
NGINX_PORT=443

# MARIADB SETUP
DB_NAME=harddrive
DB_USER=<your-login>
DB_ADMIN=overlord
DB_HOST=mariadb

# WORDPRESS SETUP
WP_TITLE=Inception
WP_ADMIN_USER=overlord
WP_ADMIN_EMAIL='overlord@student.42berlin.de'
WP_USER=<your-login>
WP_USER_EMAIL='<your-login>@student.42berlin.de'

# BONUS SETUP
BONUS=1
STATIC_PORT=8080
ADMINER=8080

```

**Step 3: Configure `/etc/hosts`**
```bash
echo "127.0.0.1    <your-login>.42.fr" | sudo tee -a /etc/hosts
```

**Step 4: Create data directories and build**
```bash
make
```

---

## Build and launch

```bash
# Mandatory services
make

# Bonus services
make bonus

# Rebuild after code changes without wiping data
make re

# Full rebuild including wiping all persistent data
make re_f
```

---

## Managing containers and volumes

**Check running containers:**
```bash
make status
# or
docker compose -f srcs/docker-compose.yml ps
```

**Shell into a container:**
```bash
make docker-nginx-exec
make docker-wordpress-exec
make docker-mariadb-exec
```

**View live logs:**
```bash
make logs           # all services
make logs-nginx
make logs-wordpress
make logs-mariadb
```

**Stop without removing data:**
```bash
make clean
```

**Full reset — removes all containers, images, and volume data:**
```bash
make fclean
```

---

## Where data is stored

Both named volumes store their data on the host machine:

```bash
docker volume inspect srcs_vol-wordpress
docker volume inspect srcs_vol-mariadb
```

The `Mountpoint` field will show `/home/<your-login>/data/wordpress` and `/home/<your-login>/data/mariadb` respectively.

Data persists across `make clean` and container restarts. Only `make fclean` removes it.

---

## Verifying the stack

**Full verification sequence:**

```bash
# 1. All containers running
docker compose -f srcs/docker-compose.yml ps

# 2. MariaDB has the correct database and users
docker compose -f srcs/docker-compose.yml exec mariadb \
    mariadb -u root -p$(cat secrets/db_root_password.txt) \
    -e "SHOW DATABASES; SELECT user, host FROM mysql.user;"

# 3. WordPress can reach MariaDB
docker compose -f srcs/docker-compose.yml exec wordpress \
    mariadb -h mariadb -u $DB_USER -p$(cat secrets/db_password.txt) $DB_NAME -e ";"

# 4. WordPress is installed
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp core is-installed --path=/var/www/html --allow-root

# 5. WordPress siteurl is correct
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp option get siteurl --path=/var/www/html --allow-root

# 6. php-fpm is listening on the correct port
docker compose -f srcs/docker-compose.yml exec wordpress \
    ss -tlnp | grep php

# 7. nginx can reach php-fpm
docker compose -f srcs/docker-compose.yml exec nginx \
    curl http://wordpress:9000

# 8. Full HTTPS chain works
curl -k https://<your-login>.42.fr/wp-login.php
```

---

## Changing ports (evaluation requirement)

All ports are controlled from `srcs/.env`:

```dotenv
DB_PORT=3306    # MariaDB listening port
WP_PORT=9000    # php-fpm listening port
NGINX_PORT=443  # nginx listening port (internal)
```

Each entrypoint script reads these variables and applies them via `sed` at container startup. After changing a port in `.env`, run:

```bash
make re
```

Note: The external port Docker maps to the host is always 443. `NGINX_PORT` controls only the internal port nginx listens on inside the container.

---

## Debugging common problems

**Containers restarting in a loop:**
```bash
docker compose -f srcs/docker-compose.yml logs <service>
```
Look for the last error before the crash.

**WordPress can't connect to MariaDB:**
```bash
# Check MariaDB is actually listening
docker compose -f srcs/docker-compose.yml exec mariadb ss -tlnp

# Test connection manually from WordPress container
docker compose -f srcs/docker-compose.yml exec wordpress \
    mariadb -h mariadb -P 3306 -u $DB_USER -p$DB_PASSWORD $DB_NAME -e ";"
```

**nginx returns 502 Bad Gateway:**
```bash
# Check php-fpm is running and listening
docker compose -f srcs/docker-compose.yml exec wordpress \
    ss -tlnp | grep php

# Check nginx can reach wordpress container
docker compose -f srcs/docker-compose.yml exec nginx \
    curl http://wordpress:9000
```

**WordPress URLs broken after port change:**
```bash
# Check stored siteurl
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp option get siteurl --path=/var/www/html --allow-root

# Fix if wrong
docker compose -f srcs/docker-compose.yml exec wordpress \
    wp option update siteurl "https://<your-login>.42.fr" \
    --path=/var/www/html --allow-root
```

**SSL certificate errors:**
The certificate is self-signed and generated at container startup. It's stored inside the nginx container at `/etc/nginx/ssl/`. It is regenerated on every fresh container start — this is expected behavior.

**Volume data missing after restart:**
```bash
ls -la /home/<your-login>/data/wordpress
ls -la /home/<your-login>/data/mariadb
```
If these directories are empty, the volumes weren't mounted correctly. Check `driver_opts` in `docker-compose.yml` and verify the host directories exist.

---

## Evaluation checklist

Before the evaluation, run the evaluator's reset command:
```bash
docker stop $(docker ps -qa)
docker rm $(docker ps -qa)
docker rmi -f $(docker images -qa)
docker volume rm $(docker volume ls -q)
docker network rm $(docker network ls -q) 2>/dev/null
```


Then verify:
- [ ] No credentials in the git repository (only in `secrets/` and `srcs/.env`, both gitignored)
- [ ] `srcs/` folder exists at repository root
- [ ] `Makefile` exists at repository root
- [ ] No `network: host`, `--link`, or `links:` in docker-compose files
- [ ] No `tail -f`, `sleep infinity`, or infinite loops in entrypoints
- [ ] All containers built from `debian:bookworm-slim` (penultimate stable Debian)
- [ ] Each image named after its service
- [ ] Port 443 works, port 80 does not
- [ ] Run `curl -k -v https://<your-login>.42.fr` to see the TLS certificates
- [ ] Check that `http://<your-login>.42.fr` doens't return sucessful.
<!-- >Remove apache if needed: `systemctl stop apache2` -->
- [ ] Check the network
<!-- >bridge — Docker's default network. Every container that doesn't specify a network gets attached to this automatically. It's always there. You don't use it.
>host — Makes a container share the host machine's network stack directly, as if it weren't containerized. No isolation. Your project explicitly forbids this (network: host is banned by the subject).
>none — Completely disables networking for a container. Used when you want a container with zero network access. Not relevant here.
>srcs_inception — This is yours. Docker Compose named it srcs_inception because your compose file is in the srcs directory (project name) and you named the network inception in your docker-compose.yml. All your containers are attached to this network and can reach each other by service name. Nothing outside this network can reach them directly — only through nginx on port 443. -->
- [ ] Two WordPress users exist (admin without "admin" in name, plus a subscriber)
- [ ] Both volumes mounted at `/home/<your-login>/data/`
- [ ] Data persists after Docker reboot
