FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	wget \
	tar \
	curl \
	openssl \
	nginx

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/nginx.key \
		-out /etc/nginx/ssl/nginx.crt \
		-subj "/CN=edugonza.42.fr"

RUN mkdir -p /var/log/nginx
RUN chown -R www-data:www-data /var/log/nginx /var/www/html || true


COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE $NGINX_PORT
VOLUME /var/www/html
ENTRYPOINT ["/entrypoint.sh"]


  # # Generate self-signed SSL certificate
  # RUN openssl req -x509 -nodes -days 365 \
  #     -subj "/C=DE/ST=Berlin/O=42Berlin/CN=gonzalo.42.fr" \
  #     -newkey rsa:2048 \
  #     -keyout /etc/ssl/private/nginx.key \
  #     -out /etc/ssl/certs/nginx.crt
