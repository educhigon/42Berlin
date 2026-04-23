FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	&& apt install wget -y \
	&& apt install tar -y
RUN apt install -y ca-certificates apt-transport-https gnupg2 software-properties-common \
	&& wget -qO /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg \
	&& echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/php.list
RUN apt-get update && apt install php8.1 php8.1-cli php8.1-fpm php8.1-mbstring php8.1-xml php8.1-mysql -y
RUN apt-get update && apt-get install php-fpm -y
RUN apt-get install mariadb-client -y
RUN apt-get install iproute2 -y
RUN ln -s /usr/sbin/php-fpm8.1 /usr/sbin/php-fpm

COPY conf/www.conf /etc/php/8.1/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE $WP_PORT
VOLUME /var/lib/html
ENTRYPOINT ["/entrypoint.sh"]

# mariadb -h mariadb -u edugonza -p1234user harddrive
