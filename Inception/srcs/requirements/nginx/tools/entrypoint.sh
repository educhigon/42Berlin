#!/bin/bash
set -e

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/nginx.key \
		-out /etc/nginx/ssl/nginx.crt \
		-subj "/CN=edugonza.42.fr"

# chown -R www-data:www-data /var/www/html
# chmod -R 755 /var/www/html
mkdir -p /var/log/nginx
chown -R www-data:www-data /var/log/nginx /var/www/html || true

# If DEBUG is set to "1" and DEBUG_IP provided, insert debug_connection
if [ "${DEBUG:-}" = "1" ] && [ -n "${DEBUG_IP:-}" ]; then
  if ! grep -q "debug_connection" /etc/nginx/nginx.conf; then
    sed -i '/events {/a\    debug_connection '"$DEBUG_IP"';' /etc/nginx/nginx.conf
  fi
  # ensure error_log level is debug (idempotent)
  if ! grep -q "error_log .*debug" /etc/nginx/nginx.conf; then
    sed -i '/http {/a\    error_log /var/log/nginx/error.log debug;' /etc/nginx/nginx.conf
  fi
fi

# Test config then start nginx in foreground
nginx -t
nginx -g 'daemon off;' &

# Tail logs to stdout (replace shell with tail so it receives signals)
exec tail -F /var/log/nginx/access.log /var/log/nginx/error.log
