FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	&& apt install wget -y \
	&& apt install tar -y \
	&& apt install curl -y

RUN apt install nginx -y


RUN cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.bak
RUN cp /etc/nginx/conf.d/default.conf /etc/nginx/conf.d/default.conf.bak || true


COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE 443
VOLUME /var/www/html
ENTRYPOINT ["/entrypoint.sh"]
