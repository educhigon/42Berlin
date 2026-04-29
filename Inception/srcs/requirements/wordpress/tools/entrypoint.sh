#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"
WP_PATH=/var/www/html

until mariadb -P "${DB_PORT}" -h "${DB_HOST}" -u "${DB_USER}" -p"${DB_PASSWORD}" "${DB_NAME}" -e ";" 2>/dev/null; do
    echo "[wordpress] Waiting for MariaDB..."
    sleep 2
done

if [ ! -f "/var/www/html/wp-config.php" ]; then
	cd /var/www/html
	mv ../../../tmp/data/* ./
	rm -rf ../../../tmp/data

	chown -R www-data:www-data /var/www/html
	chmod -R g+w wp-content

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

	# # 1. Create the page and capture its ID
	# PAGE_ID=$(wp post create \
	# 		--post_type=page \
	# 		--post_title="Home" \
	# 		--post_status=publish \
	# 		--porcelain \
	# 		--path=/var/www/html \
	# 		--post_content="$(cat home.html)" \
	# 		--allow-root)

	# # 2. Tell WordPress to use a static front page instead of latest posts
	# wp option update show_on_front page \
	# 		--path=/var/www/html \
	# 		--allow-root

	# # 3. Tell WordPress which page to use as the front page
	# wp option update page_on_front "$PAGE_ID" \
	# 		--path=/var/www/html \
	# 		--allow-root

		wp rewrite structure '/%postname%/' --path=/var/www/html --allow-root
		wp rewrite flush --path=/var/www/html --allow-root

fi

echo "==> Wordpress will be launched in port ${WP_PORT}"
sed -i "s/listen = 0.0.0.0:9000/listen = 0.0.0.0:${WP_PORT}/" /etc/php/8.2/fpm/pool.d/www.conf
# sed -i "s/define( 'DB_HOST', 'mariadb\:3306' )/define( 'DB_HOST', 'mariadb\:${DB_PORT}' )/" /var/www/html/wp-config.php
sed -i "/DB_HOST/ s/\(define([[:space:]]*'DB_HOST'[[:space:]]*,[[:space:]]*'[^:]*\):[0-9]\+\('\).*/\1:${DB_PORT}\2);/" /var/www/html/wp-config.php

# WP_URL="https://${DOMAIN_NAME}:${NGINX_PORT}"
# echo "                                  ##########"
# echo "WP_URL: ${WP_URL}"
# echo "                                  ##########"
wp option update siteurl "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
wp option update home "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root

# wp option update siteurl "${WP_URL}" --path=/var/www/html --allow-root
# wp option update home "${WP_URL}" --path=/var/www/html --allow-root

exec php-fpm -F
