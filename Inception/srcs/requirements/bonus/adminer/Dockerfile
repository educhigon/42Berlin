FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	wget \
	php \
	php-mysqli

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php \
    -O /var/www/adminer.php

EXPOSE 8080
CMD ["php", "-S", "0.0.0.0:8080", "-t", "/var/www"]

# Login to: https://localhost/adminer.php
# System: MySQL
# Server: mariadb
# Username: edugonza
# Password: ****
# Database: harddrive
