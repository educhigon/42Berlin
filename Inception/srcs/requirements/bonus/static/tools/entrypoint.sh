#!/bin/bash
set -e

echo "==> STATIC will be launched in port ${STATIC_PORT}"

sed -i "s/server_name localhost/server_name ${DOMAIN_NAME:-localhost}/" /etc/nginx/nginx.conf
sed -i "s/listen 8080 ssl/listen ${STATIC_PORT} ssl/" /etc/nginx/nginx.conf
sed -i "s/listen \[\:\:\]\:8080 ssl/listen \[\:\:\]\:${STATIC_PORT} ssl/" /etc/nginx/nginx.conf

# Test config then start nginx in foreground
nginx -t
nginx -g 'daemon off;'
