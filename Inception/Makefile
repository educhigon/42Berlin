NAME = Inception
DIR = /home/edugonza/data
DOCKER_COMPOSE_FILE = srcs/docker-compose.yml
DOCKER_COMPOSE_FILE_BONUS = srcs/b-docker-compose.yml

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
		docker compose -f $(DOCKER_COMPOSE_FILE) up --build;	\
	else \
		sed -i "/BONUS=/c\BONUS=1" ./srcs/.env; \
		docker compose -f $(DOCKER_COMPOSE_FILE_BONUS) up --build; \
	fi;

clean:
	@echo " \n\033[43m- PRINTING ALL RUNNING CONTAINERS -\033[0m"
	@docker ps
	@echo " \n\033[43m- STOPPING CONTAINERS -\033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) down
	@docker compose -f $(DOCKER_COMPOSE_FILE_BONUS) down
	@echo "\n\033[32m ----- All containers stopped! ----- \033[0m"

fclean:
	@echo "\n\033[41m - ERASING DATA - \033[0m"
	@sudo rm -rf "$(DIR)/mariadb";
	@sudo rm -rf "$(DIR)/wordpress";
	@echo "\033[32m ----- Data erased ----- \033[0m"
	@docker system prune -af
	@$(MAKE) --no-print-directory clean

status:
	@echo "\n\033[33m -- CONTAINERS -- \033[0m"
	@docker compose -f $(DOCKER_COMPOSE_FILE) ps
	@echo "\n\033[33m -- VOLUMES -- \033[0m"
	@docker volume ls
	@echo "\n\033[33m -- NETWORKS -- \033[0m"
	@docker network ls

re_f:	fclean all
re:	clean all
re_bonus:	clean bonus
re_f_bonus:	fclean bonus

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

.PHONY: all clean fclean re re_f re_bonus re_f_bonus run_docker bonus \
        check_dirs docker_live docker_mariadb_exec docker_wordpress_exec \
        docker_nginx_exec
