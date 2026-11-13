NAME            = ft_onion
COMPOSE         = docker compose

-include .env
EVAL_KEY  = $(HOME)/.ssh/ft_onion_evaluator
EVAL_TAG  = ft_onion-evaluator
KEYFILE  ?= $(EVAL_KEY).pub
TOR_PROXY = 127.0.0.1:9150

all: up
 
# mkdir first: if Docker creates a missing bind-mount folder itself, it creates it owned by root on the host.
up: .env
	$(COMPOSE) up -d --build
 
.env:
	@echo "\033[33m\n-- CHECKING ENV FILE --\033[0m"; \
	if [ ! -f .env ]; then \
		echo "\033[31m >> Missing env file: $(1)\033[0m"; \
		echo "\033[31m >> Copy .env.example to $(1) and fill in the values\033[0m"; \
		exit 1; \
	fi; \
	@printf "\033[31m >> Missing .env: cp .env.example .env and fill in the values\033[0m\n"
	
down:
	$(COMPOSE) down

reset-identities:
	$(COMPOSE) down -v

# Prints both onion addresses (tor needs a few seconds after start)
address:
	@echo "web: $$(docker exec $(NAME) cat /var/lib/tor/web/hostname)"
	@echo "ssh: $$(docker exec $(NAME) cat /var/lib/tor/ssh/hostname)"
 
logs:
	$(COMPOSE) logs -f
 
shell:
	docker exec -it $(NAME) bash
 
# Evaluation proof: no published ports, only loopback listeners
check:
	docker ps --filter name=$(NAME)
	docker exec $(NAME) ss -tlnp
 
# Generate (or regenerate) the evaluation key on THIS machine (the client)
keygen:
	@mkdir -p -m 700 $(HOME)/.ssh
	@rm -f $(EVAL_KEY) $(EVAL_KEY).pub
	@ssh-keygen -q -t ed25519 -N "" -C "$(EVAL_TAG)" -f $(EVAL_KEY)
	@echo "New key: $(EVAL_KEY) (private, stays here) + .pub (goes to the server)"

# Install a public key; the tagged evaluation key REPLACES its previous version
add-key:
	@test -f "$(KEYFILE)" || (echo "No key at $(KEYFILE): run 'make keygen' first"; exit 1)
	@grep -q '^ssh-' "$(KEYFILE)" || (echo "$(KEYFILE): not a public key"; exit 1)
	@docker exec -i -e TAG="$(EVAL_TAG)" $(NAME) sh -c '\
		KEY=$$(cat); \
		f="/home/$$SSH_USER/.ssh/authorized_keys"; \
		touch "$$f"; \
		case "$$KEY" in *" $$TAG") grep -v " $$TAG$$" "$$f" > "$$f.tmp"; mv "$$f.tmp" "$$f";; esac; \
		grep -qxF "$$KEY" "$$f" || echo "$$KEY" >> "$$f"; \
		chown "$$SSH_USER:$$SSH_USER" "$$f"; \
		chmod 600 "$$f"' < "$(KEYFILE)"
	@echo "Installed $(KEYFILE)"

# Connect through Tor Browser's proxy, offering ONLY the evaluation key
ssh:
	@ssh -i $(EVAL_KEY) -o IdentitiesOnly=yes \
		-o ProxyCommand='nc -X 5 -x $(TOR_PROXY) %h %p' \
		-p 4242 $(SSH_USER)@$$(docker exec $(NAME) cat /var/lib/tor/ssh/hostname)

clean: 
	@echo "---Removing containers---"
	@make down
 
# Removes the image. Does NOT touch the onion keys: they live outside the repo
# on purpose (delete $(ONION_KEYS_DIR) by hand to get new addresses).
fclean: 
	@make down
	@echo "---Removing images---"
	$(COMPOSE) down --rmi local
	@echo "   ==> ONION keys not removed. If you want them removed delete $(ONION_KEYS_DIR) by hand"
 
re: fclean all
 
.PHONY: all up down address logs shell check add-key clean fclean re reset-identities keygen ssh
