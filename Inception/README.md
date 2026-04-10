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


***

# Resources

- https://www.markdownguide.org/basic-syntax/
- https://www.debian.org/releases/
- https://wordpress.org/documentation/article/wordpress-versions/
- https://wordpress.org/about/requirements/
- https://github.com/docker-library/wordpress/blob/master/Dockerfile.template


- AI
	- Claude Code created a 10 Module lecture that explain everything relevant to the project in terms of containers, Dockerfiles, docker-compose and each of the settings those files need
	- Duck.ai was used to answer simple questions of file structure and settings meaning (it was my enhanced version of StackOverflow)
	- Claude Code was also used in debugging, specially to understand container startup errors and what they mean. This was important not only to solve the problem but to understand why the problem was happening, and how to solve this type of problem in the future.
	- How to create a Dockerfile:
		1. Identify the process that runs
		2. Go to that application's documentation (not Docker's) to find its requirements
		3. Work backwards from requirements to packages
		4. The entrypoint handles what can't be done at build time


***

# Project description
	•	A Project description section must also explain the use of Docker and the sources included in the project. It must indicate the main design choices, as well as a comparison between:
		◦	Virtual Machines vs Docker
		◦	Secrets vs Environment Variables
		◦	Docker Network vs Host Network
		◦	Docker Volumes vs Bind Mounts
