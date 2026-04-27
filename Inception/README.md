_This project has been created as part of the 42 curriculum by edugonza._

***

# Description
A “Description” section that clearly presents the project, including its goal and a brief overview.

The goal of the Inception project is to teach about containerization of processes.
The idea is simple, instead of having all process running in one instance, where any error could break all other processes like a domino, even if other services are functioning perfectly, we divide each process in a container and configure the structure and protocols they need to follow to communicate to one another.
With this new structure, the process need to take care of their own, and if a problem happens with any of the services, this should not impact the health of other processes.
That also helps in segmenting the problem:
- making it easier to identify the root cause
- avoid breaking sensitive flows, like memory storing
- simplify autonomous or automatic reinstation of the service

Particularly in this project we are asked to set up 3 containers:
- Database container, with MariaDB installed
- Backend container, with Wordpress installed
- API container, with NGINX installed

For the containers to be able to work together, we also need to:
- set up the volumes in which the memory is going to be persisted
- set up the network the containers will use to communicate to one another
- set the secrets and environmental variables to safeguard passwords and make the process agnostic to user
- create a comprehensive README.md file to explain in details
	- what the project aims
	- what are the contraints
	- what resources were used (specially how was AI used throughout the project)
	- what are the instructions to run the project in a new machine

***

# Instructions

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
> `make re` -> will run all commands necessary to turn on all containers

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
>

***

# Resources

- https://www.markdownguide.org/basic-syntax/
- https://www.debian.org/releases/
- https://wordpress.org/documentation/article/wordpress-versions/
- https://wordpress.org/about/requirements/
- https://github.com/docker-library/wordpress/blob/master/Dockerfile.template
- https://www.digitalocean.com/community/tutorials/how-to-install-php-8-1-and-set-up-a-local-development-environment-on-ubuntu-22-04
- https://developer.wordpress.org/advanced-administration/before-install/howto-install/


- AI
	- Claude Code created a 10 Module lecture that explain everything relevant to the project in terms of containers, Dockerfiles, docker-compose and each of the settings those files need
	- Duck.ai was used to answer simple questions of file structure and settings meaning (it was my enhanced version of StackOverflow)
	- Claude Code was also used in debugging, specially to understand container startup errors and what they mean. This was important not only to solve the problem but to understand why the problem was happening, and how to solve this type of problem in the future.
	- How to create a Dockerfile:
		1. Identify the process that runs
		2. Go to that application's documentation (not Docker's) to find its requirements
		3. Work backwards from requirements to packages
		4. The entrypoint handles what can't be done at build time

		Before writing a single line of code for each container, answer:

			1. What process runs at the end? (mysqld / php-fpm / nginx)
			2. What does that process need installed? (packages)
			3. What files does it need that don't come from packages? (WordPress files, config files)
			4. Who creates those files and when? (build time in Dockerfile, or runtime in entrypoint)
			5. What other services does it depend on?
			6. What volumes does it share with other containers?

  ---
  The network question you couldn't explain

  Every process that listens for connections binds to an address:port. The address controls who can connect.

  127.0.0.1 means "only accept connections from this same machine". It's the loopback address — traffic sent here never leaves the machine. Safe for
  local-only communication.

  0.0.0.0 means "accept connections on any network interface". Any machine that can reach this machine on the network can connect.

  In Docker, each container is a separate machine from the network's perspective. When php-fpm binds to 127.0.0.1:9000, nginx in another container tries to
  connect and gets rejected — different machine. When php-fpm binds to 0.0.0.0:9000, nginx can reach it over the Docker network. This has nothing to do with
   Docker specifically — it's how every networked process works on any OS.

  ---
  What PHP actually is in this context

  PHP is a language that runs on a server and generates HTML. When you visit a WordPress page, you're not downloading a pre-written HTML file. You're
  triggering a PHP program that queries the database, builds the page dynamically, and returns HTML to your browser.

  PHP can run in two modes:
  - CLI: you run a script directly, it executes and exits. Like running a C binary.
  - FPM (FastCGI Process Manager): a long-running process that waits for requests to execute PHP files, executes them, and returns the output. This is what
  you need for a web server.

  php-fpm is not part of WordPress. It's the engine that executes WordPress's PHP files on demand.

  ---
  What WordPress actually is

  WordPress is a content management system — a pre-written PHP application. When you download WordPress you get a folder of .php files that together
  implement a website: user login, page rendering, admin panel, database queries, everything.

  You don't write WordPress. You deploy it. Your job is to put those files somewhere php-fpm can execute them, and give it a wp-config.php that tells it
  where the database is.

  The relationship:

  nginx receives HTTP request for a page
    → passes it to php-fpm
      → php-fpm executes the relevant WordPress .php file
        → that file queries MariaDB for content
          → builds HTML
            → returns to php-fpm
              → returns to nginx
                → returns to browser

  ---
  What each file in your project is responsible for

  Dockerfile: build time only. Install packages, copy files into the image, set permissions. No runtime logic here.

  entrypoint.sh: runtime initialization. Everything that needs to happen before the main process starts — and things that depend on environment variables,
  secrets, or other containers that don't exist at build time.

  conf/ files: configuration for the service. Copied in by the Dockerfile, they configure how the process behaves when it runs.

  The rule of thumb:
  - Needs to happen once when building the image → Dockerfile
  - Needs to happen on first run or every run → entrypoint
  - Controls how the service behaves → conf file


***

# Project description
	•	A Project description section must also explain the use of Docker and the sources included in the project. It must indicate the main design choices, as well as a comparison between:
		◦	Virtual Machines vs Docker
		◦	Secrets vs Environment Variables
		◦	Docker Network vs Host Network
		◦	Docker Volumes vs Bind Mounts


  A website needs three things: something to serve files, something to execute code, and somewhere to store data. That's nginx, php-fpm, and MariaDB. Each
  one is a separate concern, which is why they're in separate containers.

  Browser
    ↓ HTTPS (port 443)
  NGINX container
    ├── serves static files directly from /var/www/html
    └── forwards PHP requests to wordpress:9000
           ↓
  WordPress container (php-fpm)
    ├── executes PHP files from /var/www/html
    └── reads/writes data to mariadb:3306
           ↓
  MariaDB container
    └── stores all WordPress data in /var/lib/mysql

  Two containers share one volume: /var/www/html. That's where WordPress files live. Both nginx and php-fpm need to read from there.

  ---
  What each container is responsible for

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
