# Inception – How to Think About It

I wanted to write this text to first help me understand this project better. For those who don't know me, I'm a former 42 student and this text is an explanation, in general terms, of one of the projects we do in the curriculum: **Inception**.

The idea of the project is to implement a WordPress service with MariaDB for data persistence and an NGINX server to forward requests. That is the goal we are pursuing:

**Before you continue reading I want to warn you:** If you like me don't like to simply copy paste code you find in the internet and want to write your own, first of all Kudos =), second, I recommend you read this article with your code editor closed. The code and the solutions are also given in this article but my main point here is to show the mental model I used to structure the solution. Of course, the result I'm showing is the answer to solve the problem, but if you just read and understand the logic you won't be copying; you will know what needs to be put where and more importantly, you will know what to search for when you find an error in your code.

With that said, let's start by reading the subject

---

## Where do we start?

The subject gives us the general structure we have to implement:

![Intended project structure](image.png)

It also gives us the suggested folder tree to start our development:

```
.
├── Makefile
├── secrets
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs
    ├── docker-compose.yml
    ├── .env
    └── requirements
        ├── bonus
        ├── mariadb
        │   ├── conf
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   └── tools
        ├── nginx
        │   ├── conf
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   └── tools
        ├── tools
        └── wordpress
            ├── conf
            ├── Dockerfile
            ├── .dockerignore
            └── tools
```

And that's it. Apart from that, we have to figure things out for ourselves.

So the first thing — if you have no idea what Docker and Dockerfiles are, I recommend you pause for a moment and look at a few details about those concepts. I have a link to another post where Claude explained to me the basics I used to make this project — it might be useful for you too.

Assuming you have already created the suggested tree and have a general understanding of Docker, you might, like me, get stuck on *exactly what to do first*. So here is what I recommend:

---

## The Makefile – giving yourself a trigger

Let's start from the beginning of your code so you can already see some things moving.

```makefile
NAME = Inception
DOCKER_COMPOSE_FILE = srcs/docker-compose.yml

all: run_docker

run_docker:
	@echo "\033[33m \n-- RUNNING DOCKER --\033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) up --build

clean:
	@echo " \n\033[43m- PRINTING ALL RUNNING CONTAINERS -\033[0m"
	@docker ps
	@echo " \n\033[43m- STOPPING CONTAINERS -\033[0m"
	@docker compose -f srcs/docker-compose.yml down
	@echo "\n\033[32m ----- All containers stopped! ----- \033[0m"

fclean:
	@docker system prune -af
	@$(MAKE) --no-print-directory clean

re_f: fclean all
re:   clean all

.PHONY: all clean fclean re re_f run_docker
```

When run, this will simply execute:

```sh
docker compose -f srcs/docker-compose.yml up --build
```

As of now, nothing should happen — we have nothing in our `docker-compose.yml`. So let's fix that.

---

## The docker-compose.yml – the blueprint of your system

This file needs to answer a few questions:

- What services will be running?
- What network will the containers share?
- What secrets are we injecting?
- What volumes exist and where?

A skeleton with those four concerns looks like this:

```yaml
services:
  mariadb:
    # (we'll fill this in below)

networks:
  inception:
    driver: bridge

secrets:
  db_password:
    file: ../secrets/db_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
  db_admin_password:
    file: ../secrets/db_admin_password.txt

volumes:
  vol-mariadb:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/mariadb
```

> **Note on `${USER}`:** Docker Compose reads variable substitutions from your `.env` file. Make sure `USER` is declared there (or exported in your shell environment) — otherwise the volume bind will fail silently. We'll cover the `.env` file shortly.

I won't go into much detail about networks, secrets, and volumes because for this project the implementation is fairly standard. What matters is the service definition itself. Each service needs:

- A name for the image
- Build details (where is the context and Dockerfile)
- Which secrets it will consume
- What environment variables it needs
- A restart policy
- Which volumes and networks it attaches to

For MariaDB, that looks like this:

```yaml
  mariadb:
    image: mariadb
    build:
      context: ./requirements/mariadb
      dockerfile: Dockerfile
    secrets:
      - db_password
      - db_admin_password
      - db_root_password
    environment:
      DB_NAME: "${DB_NAME:-mariadb}"
      DB_USER: "${DB_USER:-user1}"
      DB_ADMIN: "${DB_ADMIN:-adm}"
      DB_PORT: "${DB_PORT:-3306}"
    restart: unless-stopped
    volumes:
      - vol-mariadb:/var/lib/mysql
    networks:
      - inception
```

---

## A quick word on the `.env` file

You might have noticed variables like `${DB_NAME}` and `${DB_PORT}` appearing above without being defined anywhere yet. They come from your `.env` file, which Docker Compose automatically reads when it starts. It sits at `srcs/.env` and should declare all the variables your services depend on:

```env
DB_NAME=wordpress
DB_USER=wp_user
DB_ADMIN=wp_admin
DB_PORT=3306
USER=your_username
```

> **Why not hardcode these values directly?** Separating configuration from code means you can change your database name, ports, or usernames without touching any of the service files. It also keeps sensitive-ish config out of your Dockerfiles.

Passwords are intentionally *not* here — those go in the `secrets/` files, which we handle separately for an extra layer of safety.

---

## The Dockerfile – installing what the container needs

Until now we've only coded the *structure* of our containers and the trigger (Makefile). The actual content of what runs inside a container lives in its Dockerfile.

You might already know that a Dockerfile is like a recipe — not the cake itself. Docker follows the instructions in the Dockerfile to build whatever you want inside the container.

Now, think to yourself: if you wanted to install MariaDB on your own computer, what would you do?

```sh
sudo apt-get install mariadb-server
```

That assumes `apt-get` is available. But `apt-get` isn't part of the Linux kernel — it's a package manager that comes bundled with Debian-based distributions. A fresh container has none of that. It's a completely empty slate. That's why the very first line of every Dockerfile tells the container *where to start from* — a base image that already includes a package manager and the basic OS tooling you need.

For this project we use a slim Debian image:

```dockerfile
FROM debian:bookworm-slim
```

You can browse available Debian releases here: https://www.debian.org/releases/

With a base established, the general structure of a Dockerfile follows this logic:

1. **Start from this base image**
2. **Install everything the container needs**
3. **Copy in a configuration script (the entrypoint)**
4. **Run that script as the container's main process**

That last point is worth a search: look up **PID 1 in containers** — it explains why the last thing your entrypoint does is `exec` into the service rather than just calling it normally.

For MariaDB specifically:

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /var/lib/mysql/*

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE $DB_PORT
VOLUME ["/var/lib/mysql"]
ENTRYPOINT ["/entrypoint.sh"]
```

A couple of things worth noting:

- **`EXPOSE` and `VOLUME` are only here for clarity.**
- **`EXPOSE`** in a Dockerfile is just documentation — it doesn't actually open a port. Real port exposure is controlled by Docker Compose via the `ports:` key (for host access) or simply by sharing the same network (for container-to-container communication). MariaDB doesn't need to be reachable from your host machine — only from WordPress — so no port mapping is needed at all. The shared `inception` network handles that.
- **`VOLUME`** Since we already declared the volume in `docker-compose.yml` and bind it to `/var/lib/mysql`, adding a `VOLUME` instruction in the Dockerfile is redundant. To avoid confusion, the declaration Docker usees come from `docker-compose.yml`, we only state here for convenience.

---

## The entrypoint.sh – configuring and launching the service

This is where the real work happens. The role of the entrypoint is to:

1. Read secrets
2. First-time setup (only on a fresh start)
3. Launch the service as the main process

Let's build this **backwards** — starting from what we ultimately want, then asking *"what does that require?"* at each step. This mirrors how I actually figured it out.

### Step 1 – What do we want in the end?

We want MariaDB running:

```sh
exec mysqld --user=mysql
```

### Step 2 – What does that require?

A database and users to already exist. We can set those up with a bootstrap SQL block — `--bootstrap` lets us run SQL before the server is fully up:

```sh
mysqld --user=mysql --bootstrap << EOF

FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS ${DB_NAME};

CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';

CREATE USER IF NOT EXISTS '${DB_ADMIN}'@'%' IDENTIFIED BY '${DB_ADMIN_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO '${DB_ADMIN}'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;

EOF
```

### Step 3 – What does the bootstrap require?

A properly initialized data directory:

```sh
mysql_install_db --user=mysql --datadir=/var/lib/mysql
```

### Step 4 – But we only want to do all of this once

This is a key point. Docker will cache the image after the first build. The only thing that runs on every container start is the entrypoint. But you don't want to re-create your database every time the container restarts — the whole point of the volume is that your data *persists*.

So we wrap the setup in a guard condition: only run it if the database hasn't been initialized yet.

```sh
if [ ! -d "/var/lib/mysql/mysql" ]; then
    # first-time setup
fi
```

### Step 5 – What does that condition require?

The `/run/mysqld` socket directory to exist and be owned correctly:

```sh
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld
```

This runs unconditionally on every start (it's harmless to repeat), while everything else is guarded by the `if`.

### Step 6 – And before any of that, read the secrets

As we were using some variable values in step 2, we need to retrieve their values from the secrets and from .env.
For the secrets:
Docker Compose makes secrets available as files under `/run/secrets/`. We read them at the top:

```sh
DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)"
DB_PASSWORD="${DB_PASSWORD:-1234}"

DB_ADMIN_PASSWORD="$(cat /run/secrets/db_admin_password 2>/dev/null)"
DB_ADMIN_PASSWORD="${DB_ADMIN_PASSWORD:-1234}"

DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password 2>/dev/null)"
DB_ROOT_PASSWORD="${DB_ROOT_PASSWORD:-1234}"
```

The `:-1234` fallback means: if the secret file doesn't exist (e.g. local testing without secrets), use `1234` as a default. **Don't use this in production.**

For both the secrets and the other variables, your Dockerfile needs to make them available. That's why we write in the Dockerfile:

```yaml
    secrets:
      - db_password
      - db_admin_password
      - db_root_password
    environment:
      DB_NAME: "${DB_NAME:-mariadb}"
      DB_USER: "${DB_USER:-user1}"
      DB_ADMIN: "${DB_ADMIN:-adm}"
      DB_PORT: "${DB_PORT:-3306}"

```
So you can freely access them in your entrypoint.sh

---

### Putting it all together

Reading top-to-bottom now, everything should make sense:

```sh
#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)"
DB_PASSWORD="${DB_PASSWORD:-1234}"

DB_ADMIN_PASSWORD="$(cat /run/secrets/db_admin_password 2>/dev/null)"
DB_ADMIN_PASSWORD="${DB_ADMIN_PASSWORD:-1234}"

DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password 2>/dev/null)"
DB_ROOT_PASSWORD="${DB_ROOT_PASSWORD:-1234}"

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --bootstrap << EOF

FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS ${DB_NAME};

CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';

CREATE USER IF NOT EXISTS '${DB_ADMIN}'@'%' IDENTIFIED BY '${DB_ADMIN_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO '${DB_ADMIN}'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;

EOF
fi

echo "==> MariaDB will be launched on port ${DB_PORT}"
exec mysqld --user=mysql
```


---

## Checkpoint – Is MariaDB actually running?

Before moving on, let's verify things are working. Run:

```sh
make
```

Docker should build the image and start the container. From here, let's check things at three levels: the container itself, the network, and the database.

---

### 1. Is the container up?

```sh
docker ps
```

You should see your MariaDB container listed with status `Up`. This alone doesn't tell you much beyond "it didn't immediately crash" — let's go deeper.

For the full picture of what Docker actually configured — networks, mounts, environment variables, restart policy — use:

```sh
docker inspect srcs-mariadb-1
```

This is probably the most useful debugging command you'll encounter in this project. Any time something behaves unexpectedly, `docker inspect` tells you what Docker *actually* set up versus what you *thought* you configured. Get used to it early.

---

### 2. What is the container actually running?

Open a shell inside the container:

```sh
docker exec -it srcs-mariadb-1 bash
```

**Check what ports the service is listening on:**

```sh
ss -tuln
```

Breaking down the flags — because you'll use this again:

| Flag | Meaning |
|------|---------|
| `-t` | TCP sockets |
| `-u` | UDP sockets |
| `-l` | listening sockets only (not established connections) |
| `-n` | show port numbers instead of resolving service names |

You should see MariaDB listening on `127.0.0.1:3306` (or whatever `DB_PORT` you configured). If nothing shows up on that port, the service didn't start correctly.

> **Hold that thought.** `127.0.0.1` means the service is only reachable from *inside* the container — loopback only. That's going to be a problem when WordPress tries to connect to it from a different container. We'll come back to fix this once WordPress is in the picture and you can see the failure for yourself.

**Check the actual config file MariaDB is using:**

```sh
cat /etc/mysql/mariadb.conf.d/50-server.cnf
```

This is interesting because it shows you the real runtime configuration — bind address, port, socket path, data directory. It's the difference between "what I told Docker to do" and "what MariaDB thinks it's doing." If the port or bind address looks wrong, this is where you'll find out.
This is straightforward and standard in MariaDB, but it will be important for the next two containers.

**Check the container's activity logs:**

```sh
cat /var/log/dpkg.log
cat /var/log/alternatives.log
```

These show what was installed inside the container and when — useful to confirm that the `apt-get install` step in your Dockerfile actually ran as expected.

---

### 3. Is the database configured correctly?

Connect to MariaDB as root:

```sh
docker exec -it srcs-mariadb-1 mariadb -u root -p
# enter your DB_ROOT_PASSWORD when prompted
```

Then run:

```sql
-- Are your databases there?
SHOW DATABASES;

-- Are your tables there? (replace with your DB_NAME)
SHOW TABLES FROM <DB_NAME>;

-- Inspect table contents if needed
SELECT * FROM <DB_NAME>.<table_name>;

-- Were the users created correctly?
SELECT user, host FROM mysql.user;
```

If you see your `DB_NAME` in the database list and your `DB_USER` and `DB_ADMIN` in the users table — MariaDB is configured correctly.

---

### What about testing from outside the container?

You might wonder: can I send a request to MariaDB from my host machine to verify it's reachable?

Technically yes — but it would require exposing MariaDB's port to the host, which we deliberately didn't do. In this architecture, MariaDB is only supposed to be reachable by WordPress, through the shared Docker network. Exposing it to the host would be a security mistake in a real setup.

The meaningful connectivity test — "can WordPress actually talk to MariaDB?" — is something we'll verify at the WordPress checkpoint, once both containers are running. That's the test that actually reflects the production behaviour of your system.

---

## The framework

Alright, so after doing the first container, we can already see a pattern we can follow:

1. Create the service in Docker-compose;
2. Create the Dockerfile for that service;
3. Create the entrypoint that will call the program you need in that container;
4. Make sure the config files are tuned for what you need;
5. Test your implementation double checking what is actually running.

We will now apply that sequence to every new container we need to create.

## WordPress

Now that we know the pattern, we can move faster. The sequence is the same: compose service → Dockerfile → entrypoint.

---

### 1. Add the service to docker-compose.yml

```yaml
  wordpress:
    image: wordpress
    build:
      context: ./requirements/wordpress
      dockerfile: Dockerfile
    secrets:
      - db_password
    environment:
      WP_ADMIN_USER: "${WP_ADMIN_USER:-user}"
      WP_ADMIN_PASSWORD: "${WP_ADMIN_PASSWORD:-1234}"
      WP_ADMIN_EMAIL: "${WP_ADMIN_EMAIL:-user@user.com}"
      DB_HOST: "${DB_HOST:-mariadb}"
      DB_NAME: "${DB_NAME:-wordpress}"
      DB_USER: "${DB_USER:-user1}"
      DB_PORT: "${DB_PORT:-3306}"
      WP_PORT: "${WP_PORT:-9000}"
    restart: unless-stopped
    depends_on:
      - mariadb
    volumes:
      - vol-wordpress:/var/www/html
    networks:
      - inception
```

A few things worth unpacking here:

**`depends_on`** tells Docker Compose to start the `mariadb` container before this one. That helps, but it doesn't fully solve the connection problem — `depends_on` only waits for the container to *start*, not for MariaDB to actually be *ready to accept connections*. WordPress can still try to connect before MariaDB finishes initializing. Keep that in mind — we'll handle it properly in the entrypoint.

**`DB_HOST: "${DB_HOST:-mariadb}"`** — this is worth pausing on. How does WordPress know where to find MariaDB? There are no IP addresses here. Docker Compose automatically creates a DNS entry for each service name on the shared network, so the hostname `mariadb` resolves to the MariaDB container. This is how containers find each other — by service name, not by IP.

**The volume** is different from MariaDB's. Each service gets its own volume for its own data. The MariaDB volume holds the database files — nothing else mounts it, which is what keeps it isolated. The WordPress volume holds WP's own persistent data: themes, uploads, configuration. Two different concerns, two different volumes. And since we're adding a new one, the docker-compose.yml needs to know about it:

```yaml
  vol-wordpress:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/wp
```

---

### 2. The Dockerfile

Same thought model as before. The recipe will now call the Dockerfile from the WordPress directory — so let's think through what WordPress actually needs.

WordPress is a PHP program. That means for it to run, you need PHP installed. But it's not just one thing — there are a few pieces:

- The **PHP runtime and extensions** that WordPress depends on to function
- The **WordPress files themselves**, downloaded and extracted into the right place
- The **WP-CLI tool**, which lets you configure WordPress from a script

That last one is worth pausing on. If you don't use WP-CLI, every time WordPress starts it will think it's the first time — and it will block everything behind an interactive setup wizard until you complete it manually. WP-CLI lets you create users, set credentials, and configure the site entirely inside your entrypoint script. When the container finishes starting up, WordPress is already initialized and ready to serve content.

Lastly, WordPress needs to talk to the database — but it can't know what *type* of database it's connecting to on its own.
In the MariaDB container we installed the **server**. Here, in the WordPress container, we need to install the **client** — the piece that knows how to speak to a MariaDB server from the outside.

So in summary, here's what we need to install and set up:

```dockerfile
RUN apt-get update && apt-get install -y \
    php8.2 \
    php8.2-cli \
    php8.2-fpm \
    php8.2-mbstring \
    php8.2-xml \
    php8.2-mysql \
    mariadb-client

RUN mkdir -p /var/www/html/

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz -C /var/www/html/ --strip-components=1 \
    && rm latest.tar.gz

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && mv wp-cli.phar /usr/bin/wp \
    && chmod +x /usr/bin/wp
```

Just like before — if you're using something, make sure it's installed. We need `wget` and `tar` to run those download commands, so they go at the top, before anything else:

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    wget \
    tar
```

**Warning #1:** In this example I'm using `php8.2`, but you can use any version you prefer. Just bear in mind that the binary installed by `php8.2-fpm` will be named `php-fpm8.2` — with the version number. Many scripts and tools just call `php-fpm` without the version suffix, so it's safe to add a symlink that bridges the two:

```dockerfile
RUN ln -s /usr/sbin/php-fpm8.2 /usr/sbin/php-fpm
```

**Warning #2:** Remember how MariaDB had a config file at `/etc/mysql/mariadb.conf.d/50-server.cnf`? WordPress (via PHP-FPM) has the same kind of thing. Rather than editing the default file in place, it's simpler to replace it entirely with our own — that way we control exactly what's in it. So we add:

```dockerfile
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
```

We'll look at what goes inside `www.conf` when we get to NGINX — because the address PHP-FPM listens on is exactly what NGINX needs to know to forward requests to WordPress.

Putting it all together, the complete Dockerfile looks like this:

```dockerfile
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    wget \
    tar \
    php8.2 \
    php8.2-cli \
    php8.2-fpm \
    php8.2-mbstring \
    php8.2-xml \
    php8.2-mysql \
    mariadb-client

RUN mkdir -p /var/www/html/

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz -C /var/www/html/ --strip-components=1 \
    && rm latest.tar.gz

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && mv wp-cli.phar /usr/bin/wp \
    && chmod +x /usr/bin/wp

RUN ln -s /usr/sbin/php-fpm8.2 /usr/sbin/php-fpm

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE $WP_PORT
VOLUME /var/www/html

ENTRYPOINT ["/entrypoint.sh"]
```

`EXPOSE` and `VOLUME` are only here for clarity — same logic as MariaDB. `EXPOSE` is documentation only; real port access is handled by the shared network. `VOLUME` is redundant with the docker-compose.yml declaration, which is the one Docker actually uses. We state both here for convenience.

---

### 3. The entrypoint.sh

Great, so now we have the Dockerfile ready calling our entrypoint.sh, the file that will call the main service we want to run in this container:

```bash
exec php-fpm -F
```

We already know a few things we will need in this doc, right? Secrets and .env variables go in the beginning:

```bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"
WP_PATH=/var/www/html
```

We said we wanted this service to run only after MariaDB is running, not onl after the MariaDB container is triggered, so:

```bash
until mariadb -P "${DB_PORT}" -h "${DB_HOST}" -u "${DB_USER}" -p"${DB_PASSWORD}" "${DB_NAME}" -e ";" 2>/dev/null; do
    echo "[wordpress] Waiting for MariaDB..."
    sleep 2
done
```

Just like with MariaDB we need to configure the startup of WordPress:

```bash
if [ ! -f "/var/www/html/wp-config.php" ]; then
	chown -R www-data:www-data /var/www/html
	chmod -R g+w wp-content

	find /var/www/html -type d -exec chmod 755 {} \;
	find /var/www/html -type f -exec chmod 644 {} \;

	echo "Create wp-config.php with DB credentials from the .env file."
	wp config create \
			--path="${WP_PATH}" \
			--dbname="${DB_NAME}" \
			--dbuser="${DB_USER}" \
			--dbpass="${DB_PASSWORD}" \
			--dbhost="${DB_HOST}:${DB_PORT}" \
			--allow-root

	echo "Install WordPress (creates tables, sets admin credentials)."
	wp core install \
			--path="${WP_PATH}" \
			--url="https://${DOMAIN_NAME}" \
			--title="${WP_TITLE}" \
			--admin_user="${WP_ADMIN_USER}" \
			--admin_password="${WP_ADMIN_PASSWORD}" \
			--admin_email="${WP_ADMIN_EMAIL}" \
			--skip-email \
			--allow-root

	echo "Create USER."
	wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
			--path="${WP_PATH}" \
			--user_pass="${WP_USER_PASSWORD}" \
			--role=subscriber \
			--allow-root

	wp rewrite structure '/%postname%/' --path=/var/www/html --allow-root
	wp rewrite flush --path=/var/www/html --allow-root

fi
```

Let me go in details here:
- The condition is only true when the container is in fresh start:
wp-config.php is a config file that only exists after you run `wp core install`, and because we run this inside the if clause, this will only run once.

- We need to change the ownership of the Volume folder because...
That comes with also setting the right permissions for the folder

- wp config create does

- wp core install does

- wp user create is self explanatory, but it is important we do here because..

Lastly, we add:
- wp rewrite ...  because

So the whole file becomes:

```bash
#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"
WP_PATH=/var/www/html

until mariadb -P "${DB_PORT}" -h "${DB_HOST}" -u "${DB_USER}" -p"${DB_PASSWORD}" "${DB_NAME}" -e ";" 2>/dev/null; do
    echo "[wordpress] Waiting for MariaDB..."
    sleep 2
done

if [ ! -f "/var/www/html/wp-config.php" ]; then
	chown -R www-data:www-data /var/www/html
	chmod -R g+w wp-content

	find /var/www/html -type d -exec chmod 755 {} \;
	find /var/www/html -type f -exec chmod 644 {} \;

	echo "Create wp-config.php with DB credentials from the .env file."
	wp config create \
			--path="${WP_PATH}" \
			--dbname="${DB_NAME}" \
			--dbuser="${DB_USER}" \
			--dbpass="${DB_PASSWORD}" \
			--dbhost="${DB_HOST}:${DB_PORT}" \
			--allow-root

	echo "Install WordPress (creates tables, sets admin credentials)."
	wp core install \
			--path="${WP_PATH}" \
			--url="https://${DOMAIN_NAME}" \
			--title="${WP_TITLE}" \
			--admin_user="${WP_ADMIN_USER}" \
			--admin_password="${WP_ADMIN_PASSWORD}" \
			--admin_email="${WP_ADMIN_EMAIL}" \
			--skip-email \
			--allow-root

	echo "Create USER."
	wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
			--path="${WP_PATH}" \
			--user_pass="${WP_USER_PASSWORD}" \
			--role=subscriber \
			--allow-root

	wp rewrite structure '/%postname%/' --path=/var/www/html --allow-root
	wp rewrite flush --path=/var/www/html --allow-root
fi

echo "==> Wordpress will be launched in port ${WP_PORT}"
exec php-fpm -F

```

### 4. The config file

Alright, so now if we run the container, we will not be able to
