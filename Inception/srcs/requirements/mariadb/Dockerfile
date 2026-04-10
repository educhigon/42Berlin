FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
		mariadb-server \
		&& rm -rf /var/lib/apt/lists/* \
		&& rm -rf /var/lib/mysql/*

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
EXPOSE $DB_PORT
VOLUME ["/var/lib/mysql"]
ENTRYPOINT ["/entrypoint.sh"]
