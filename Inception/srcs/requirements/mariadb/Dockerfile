FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
	&& apt install wget -y \
	&& apt install tar -y \
	&& apt install curl -y

RUN apt-get install mariadb-server -y \
		&& rm -rf /var/lib/apt/lists/* \
		&& rm -rf /var/lib/mysql/*

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE $DB_PORT
VOLUME ["/var/lib/mysql"]
ENTRYPOINT ["/entrypoint.sh"]
