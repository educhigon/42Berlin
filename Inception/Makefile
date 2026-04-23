# Change this for eval => /home/gonzalo/code/educhigon/1.Learning/ <=> /home/login/data/
NAME = xxxxxxx
DIR = /home/gonzalo/code/educhigon/1.Learning
DOCKER_COMPOSE_FILE = srcs/docker-compose.yml

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
	echo "\033[32m All secrets present! \n\033[0m"; \


all: check_dirs run_docker

testing: check_dirs
	@$(MAKE) --no-print-directory run_docker TESTING=1

check_dirs:
	@echo "\033[33m \n-- CHECKING FOLDERS --\033[0m"
	@$(call check_dir,mariadb)
	@$(call check_dir,wordpress)
	@echo "\033[32m All Directories ready! \n\033[0m"; \

run_docker:
	@echo "\033[33m \n-- RUNNING DOCKER --\033[0m"
	@$(call escape_if_no_secret)
	@DOCKER_BUILDKIT=1 $(if $(TESTING),docker compose -f $(DOCKER_COMPOSE_FILE) build --progress=plain &&,) docker compose -f $(DOCKER_COMPOSE_FILE) up --build

clean:
	@echo " \n\033[43m- PRINTING ALL RUNNING CONTAINERS -\033[0m"
	@docker ps
	@echo " \n\033[43m- STOPPING CONTAINERS -\033[0m"
# 	Get all current running containers running and kill one by one with
# 	docker stop XXXXX

fclean:
	@echo "\n\033[41m - ERASING DATA - \033[0m"
	@sudo rm -rf "$(DIR)/mariadb";
	@sudo rm -rf "$(DIR)/wordpress";
	@echo "\033[32m ----- Data erased ----- \033[0m"
	@$(MAKE) --no-print-directory clean

re:	fclean all

.PHONY: all clean fclean re run_docker
