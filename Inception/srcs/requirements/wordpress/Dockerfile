FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	&& apt install wget -y
	# && apt install tar -y \
RUN apt install -y ca-certificates apt-transport-https gnupg2 software-properties-common \
	&& wget -qO /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg \
	&& echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/php.list

RUN apt update \
	&& apt install php8.1 php8.1-cli php8.1-fpm php8.1-mbstring php8.1-xml php8.1-mysql -y\
	&& apt-get install php-fpm -y

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE $WP_PORT
VOLUME ["/var/lib/html"]
ENTRYPOINT ["/entrypoint.sh"]
