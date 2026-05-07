FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	wget \
	tar \
	curl \
	nginx

RUN mkdir -p /var/www/static

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/entrypoint.sh /entrypoint.sh

COPY tools/data /var/www/static

RUN chmod +x /entrypoint.sh
EXPOSE $STATIC_PORT
ENTRYPOINT ["/entrypoint.sh"]
