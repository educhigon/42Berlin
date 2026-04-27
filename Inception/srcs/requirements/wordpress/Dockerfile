FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	&& apt install wget -y \
	&& apt install tar -y \
	&& apt install curl -y
RUN apt-get install iproute2 -y

RUN apt-get update && apt install -y \
		php8.2 \
		php8.2-cli \
		php8.2-fpm \
		php8.2-mbstring \
		php8.2-xml \
		php8.2-mysql

RUN apt-get update && apt-get install php-fpm -y
RUN apt-get install mariadb-client -y
RUN mkdir -p /tmp && cd /tmp

RUN wget https://wordpress.org/latest.tar.gz \
	&& tar -xzf latest.tar.gz --strip-components=1 \
	&& rm latest.tar.gz
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& mv wp-cli.phar /usr/bin/wp \
	&& chmod +x /usr/bin/wp
RUN cd ../
RUN ln -s /usr/sbin/php-fpm8.2 /usr/sbin/php-fpm
RUN chmod -R g+w wp-content

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh

RUN mkdir -p /var/www/html/
ADD tools/data ./tmp/data

RUN chmod +x /entrypoint.sh
EXPOSE $WP_PORT
VOLUME /var/www/html
ENTRYPOINT ["/entrypoint.sh"]

# mariadb -h mariadb -u edugonza -p1234user harddrive
