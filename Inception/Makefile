############## DECLARATIONS ##############
NAME = Inception
DIR = /home/edugonza/data
DOCKER_COMPOSE_FILE = srcs/docker-compose.yml
DOCKER_COMPOSE_FILE_BONUS = srcs/b-docker-compose.yml
############## DECLARATIONS ##############

############## HELPER FUNCTIONS ##############
check_dir = \
	if [ ! -d "$(DIR)/$(1)" ]; then \
		mkdir -p "$(DIR)/$(1)"; \
		echo "Created $(DIR)/$(1)"; \
	else \
		echo "Dir $(DIR)/$(1) already exists"; \
	fi; \

escape_if_no_secret = \
	echo "Checking if all secret files are present"; \
	if [ ! -d "./secrets" ]; then\
		echo "\033[31m >> Missing folder secrets \n\033[0m"; \
		exit 1; fi; \
	if [ ! -f "./secrets/db_admin_password.txt" ]; then \
		echo "\033[31m >> Missing file: db_admin_password.txt \n\033[0m"; \
		exit 1; fi; \
	if [ ! -f "./secrets/db_password.txt" ]; then \
		echo "\033[31m >> Missing file: db_password.txt \n\033[0m"; \
		exit 1; fi; \
	if [ ! -f "./secrets/db_root_password.txt" ]; then \
		echo "\033[31m >> Missing file: db_root_password.txt \n\033[0m"; \
		exit 1; fi; \
	if [ ! -f "./secrets/wp_user_password.txt" ]; then \
		echo "\033[31m >> Missing file: wp_user_password.txt \n\033[0m"; \
		exit 1; fi; \
	if [ ! -f "./secrets/wp_admin_password.txt" ]; then \
		echo "\033[31m >> Missing file: wp_admin_password.txt \n\033[0m"; \
		exit 1; fi; \
	echo "\n\033[32m ----- All secrets present! ----- \033[0m"
############## HELPER FUNCTIONS ##############

############## RUN TARGETS ##############
all: check_dirs run_docker

bonus: check_dirs
	@$(MAKE) --no-print-directory run_docker BONUS=1

check_dirs:
	@echo "\033[33m \n-- CHECKING FOLDERS --\033[0m"
	@$(call check_dir,mariadb)
	@$(call check_dir,wordpress)
	@echo "\n\033[32m ----- All Directories ready! ----- \033[0m"

run_docker:
	@echo "\033[33m \n-- RUNNING DOCKER --\033[0m"
	@$(call escape_if_no_secret)
	@if [ ! $(BONUS) ]; then \
		sed -i "/BONUS=/c\BONUS=0" ./srcs/.env; \
		docker compose -f $(DOCKER_COMPOSE_FILE) up --build --remove-orphans;	\
	else \
		sed -i "/BONUS=/c\BONUS=1" ./srcs/.env; \
		docker compose -f $(DOCKER_COMPOSE_FILE_BONUS) up --build --remove-orphans; \
	fi;
############## RUN TARGETS ##############

############## CLEAN TARGETS ##############
stop:
	@echo "\033[33m \n-- STOPPING CONTAINERS --\033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) stop 2>/dev/null || true
	@docker compose -f $(DOCKER_COMPOSE_FILE_BONUS) stop 2>/dev/null || true
	@echo "\n\033[32m ----- Containers stopped! ----- \033[0m"

clean:
	@echo " \n\033[43m- PRINTING ALL RUNNING CONTAINERS -\033[0m"
	@docker ps
	@echo " \n\033[43m- STOPPING CONTAINERS -\033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) down
	@docker compose -f $(DOCKER_COMPOSE_FILE_BONUS) down
	@echo "\n\033[32m ----- All containers stopped! ----- \033[0m"

erase_volumes:
	@echo "\n\033[41m - ERASING DATA - \033[0m"
	@sudo rm -rf "$(DIR)/mariadb";
	@sudo rm -rf "$(DIR)/wordpress";
	@echo "\033[32m ----- Data erased ----- \033[0m"

fclean:
	@$(MAKE) --no-print-directory erase_volumes
	@$(MAKE) --no-print-directory clean
	@docker system prune -af
############## CLEAN TARGETS ##############

############## STATUS AND DEBUG TARGETS ##############
status:
	@echo "\n\033[33m -- CONTAINERS -- \033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) ps
	@echo "\n\033[33m -- VOLUMES -- \033[0m"
	@docker volume ls
	@echo "\n\033[33m -- NETWORKS -- \033[0m"
	@docker network ls

docker_live:
	@echo "\n\033[33m -- LIVE LOGS -- \033[0m"
	@docker ps

docker_mariadb_exec:
	@docker compose -f $(DOCKER_COMPOSE_FILE) exec mariadb bash

docker_wordpress_exec:
	@docker compose -f $(DOCKER_COMPOSE_FILE) exec wordpress bash

docker_nginx_exec:
	@docker compose -f $(DOCKER_COMPOSE_FILE) exec nginx bash

logs:
	@docker compose -f $(DOCKER_COMPOSE_FILE) logs -f

logs-nginx:
	@docker compose -f $(DOCKER_COMPOSE_FILE) logs -f nginx

logs-wordpress:
	@docker compose -f $(DOCKER_COMPOSE_FILE) logs -f wordpress

logs-mariadb:
	@docker compose -f $(DOCKER_COMPOSE_FILE) logs -f mariadb

help:
	@echo ""
	@echo "\033[1mInception — Available targets\033[0m"
	@echo ""
	@echo "\033[33mCore:\033[0m"
	@echo "  \033[32mall\033[0m               Build and start mandatory services (nginx, wordpress, mariadb)"
	@echo "  \033[32mbonus\033[0m             Build and start all services including bonus (redis, adminer, static)"
	@echo "  \033[32mstop\033[0m              Stop running containers without removing them"
	@echo "  \033[32mclean\033[0m             Stop and remove all running containers"
	@echo "  \033[32mfclean\033[0m            Stop containers, remove images, and erase all persistent data"
	@echo ""
	@echo "\033[33mRebuild:\033[0m"
	@echo "  \033[32mre\033[0m                Clean and restart mandatory services (data preserved)"
	@echo "  \033[32mre_f\033[0m              Full reset and restart mandatory services (data wiped)"
	@echo "  \033[32mre_bonus\033[0m          Clean and restart bonus services (data preserved)"
	@echo "  \033[32mre_f_bonus\033[0m        Full reset and restart bonus services (data wiped)"
	@echo ""
	@echo "\033[33mDebug — Containers:\033[0m"
	@echo "  \033[32mdocker_live\033[0m       Show currently running containers"
	@echo "  \033[32mdocker_nginx_exec\033[0m     Open a shell inside the nginx container"
	@echo "  \033[32mdocker_wordpress_exec\033[0m Open a shell inside the wordpress container"
	@echo "  \033[32mdocker_mariadb_exec\033[0m   Open a shell inside the mariadb container"
	@echo ""
	@echo "\033[33mDebug — Logs:\033[0m"
	@echo "  \033[32mlogs\033[0m              Stream live logs from all services"
	@echo "  \033[32mlogs-nginx\033[0m        Stream live logs from nginx only"
	@echo "  \033[32mlogs-wordpress\033[0m    Stream live logs from wordpress only"
	@echo "  \033[32mlogs-mariadb\033[0m      Stream live logs from mariadb only"
	@echo ""
	@echo "\033[33mData:\033[0m"
	@echo "  \033[32merase_volumes\033[0m     Remove persistent data from host (mariadb + wordpress volumes)"
	@echo ""
	@echo "\033[33mInfo:\033[0m"
	@echo "  \033[32mhelp\033[0m              Show this message"
	@echo ""
############## STATUS AND DEBUG TARGETS ##############

re_f:	fclean all
re:	clean all
re_bonus:	clean bonus
re_f_bonus:	fclean bonus

.PHONY: all clean fclean re re_f re_bonus re_f_bonus run_docker bonus \
        check_dirs docker_live docker_mariadb_exec docker_wordpress_exec \
        docker_nginx_exec erase_volumes logs logs-nginx logs-wordpress logs-mariadb help
