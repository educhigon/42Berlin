FROM debian:bookworm-slim
 
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        tor nginx openssh-server iproute2 sudo\
    && rm -rf /var/lib/apt/lists/* \
	&& rm -f /etc/nginx/sites-enabled/default \
    && mkdir -p /run/sshd \
	&& rm -f /etc/ssh/ssh_host_*

COPY torrc        /etc/tor/torrc
COPY nginx.conf   /etc/nginx/nginx.conf
COPY sshd_config  /etc/ssh/sshd_config
COPY index.html   /var/www/html/index.html
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
 

ENTRYPOINT ["/entrypoint.sh"]
