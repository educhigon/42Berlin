NAME = Inception
DIR = /home/edugonza/data
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
	echo "\n\033[32m ----- All secrets present! ----- \033[0m"

all: check_dirs run_docker

testing: check_dirs
	@$(MAKE) --no-print-directory run_docker TESTING=1

check_dirs:
	@echo "\033[33m \n-- CHECKING FOLDERS --\033[0m"
	@$(call check_dir,mariadb)
	@$(call check_dir,wordpress)
	@echo "\n\033[32m ----- All Directories ready! ----- \033[0m"

run_docker:
	@echo "\033[33m \n-- RUNNING DOCKER --\033[0m"
	@$(call escape_if_no_secret)
	@DOCKER_BUILDKIT=1 $(if $(TESTING),docker compose -f $(DOCKER_COMPOSE_FILE) build --progress=plain &&,) docker compose -f $(DOCKER_COMPOSE_FILE) up --build

clean:
	@echo " \n\033[43m- PRINTING ALL RUNNING CONTAINERS -\033[0m"
	@docker ps
	@echo " \n\033[43m- STOPPING CONTAINERS -\033[0m"
	@docker compose -f srcs/docker-compose.yml down
	@echo "\n\033[32m ----- All containers stopped! ----- \033[0m"

fclean:
	@echo "\n\033[41m - ERASING DATA - \033[0m"
	@sudo rm -rf "$(DIR)/mariadb";
	@sudo rm -rf "$(DIR)/wordpress";
	@echo "\033[32m ----- Data erased ----- \033[0m"
	@docker system prune -af
	@$(MAKE) --no-print-directory clean

re_f:	fclean all
re:	clean all

.PHONY: all clean fclean re re_f run_docker
