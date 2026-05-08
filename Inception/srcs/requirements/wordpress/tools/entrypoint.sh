#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"
WP_USER_PASSWORD="$(cat /run/secrets/wp_user_password 2>/dev/null)";
WP_USER_PASSWORD="${WP_USER_PASSWORD:-1234}"
WP_ADMIN_PASSWORD="$(cat /run/secrets/wp_admin_password 2>/dev/null)";
WP_ADMIN_PASSWORD="${WP_ADMIN_PASSWORD:-1234}"
WP_PATH=/var/www/html

until mariadb -P "${DB_PORT}" -h "${DB_HOST}" -u "${DB_USER}" -p"${DB_PASSWORD}" "${DB_NAME}" -e ";" 2>/dev/null; do
    echo "[wordpress] Waiting for MariaDB..."
    sleep 2
done

if [ ! -f "/var/www/html/wp-config.php" ]; then
	chown -R www-data:www-data /var/www/html
	chmod -R g+w /var/www/html/wp-content

	find /var/www/html -type d -exec chmod 755 {} \;
	find /var/www/html -type f -exec chmod 644 {} \;

	echo "Create wp-config.php with DB credentials from the .env file."
	wp config create \
			--path="${WP_PATH}" \
			--dbname="${DB_NAME}" \
			--dbuser="${DB_USER}" \
			--dbpass="${DB_PASSWORD}" \
			--dbhost="${DB_HOST}:${DB_PORT}" \
			--allow-root

	echo "Install WordPress (creates tables, sets admin credentials)."
	wp core install \
			--path="${WP_PATH}" \
			--url="https://${DOMAIN_NAME}" \
			--title="${WP_TITLE}" \
			--admin_user="${WP_ADMIN_USER}" \
			--admin_password="${WP_ADMIN_PASSWORD}" \
			--admin_email="${WP_ADMIN_EMAIL}" \
			--skip-email \
			--allow-root

	echo "Create USER."
	wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
			--path="${WP_PATH}" \
			--user_pass="${WP_USER_PASSWORD}" \
			--role=subscriber \
			--allow-root

	wp rewrite structure '/%postname%/' --path=/var/www/html --allow-root
	wp rewrite flush --path=/var/www/html --allow-root

fi

echo "==> Wordpress will be launched in port ${WP_PORT}"
sed -i "s/listen = 0.0.0.0:9000/listen = 0.0.0.0:${WP_PORT}/" /etc/php/8.2/fpm/pool.d/www.conf
sed -i "/DB_HOST/ s/\(define([[:space:]]*'DB_HOST'[[:space:]]*,[[:space:]]*'[^:]*\):[0-9]\+\('\).*/\1:${DB_PORT}\2);/" /var/www/html/wp-config.php


if [ "${BONUS}" = 1 ]; then
	until (echo > /dev/tcp/redis/6379) 2>/dev/null; do
		echo "[wordpress] Waiting for Redis..."
		sleep 2
	done
	# Install and activate the Redis plugin
	wp plugin install redis-cache --activate \
			--path="${WP_PATH}" --allow-root

	# Add Redis connection details to wp-config.php
	wp config set WP_REDIS_HOST redis --path="${WP_PATH}" --allow-root
	wp config set WP_REDIS_PORT 6379 --path="${WP_PATH}" --allow-root

	# Enable the Redis object cache
	wp redis enable --path="${WP_PATH}" --allow-root
else
	rm -f "${WP_PATH}/wp-content/object-cache.php"
	wp config delete WP_REDIS_HOST --path="${WP_PATH}" --allow-root 2>/dev/null || true
	wp config delete WP_REDIS_PORT --path="${WP_PATH}" --allow-root 2>/dev/null || true
fi


wp option update siteurl "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
wp option update home "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root

exec php-fpm -F
