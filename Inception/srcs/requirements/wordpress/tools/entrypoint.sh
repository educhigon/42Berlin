#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"
WP_PATH=/var/www/html

until mariadb -h "${DB_HOST}" -u "${DB_USER}" -p"${DB_PASSWORD}" "${DB_NAME}" -e ";" 2>/dev/null; do
    echo "[wordpress] Waiting for MariaDB..."
    sleep 2
done


# https://localhost/?page_id=2
if [ -d "./tmp/data" ]; then
	cd /var/www/html
	mv ../../../tmp/data/* ./
	# if [ -z "$(ls -A )" ]; then
	# 	mv ../../../tmp/data/* ./
	# 	echo "####################### =====>  Empty"
	# else
	# 	ls -la
	# 	echo "####################### =====>  Not Empty"
	# fi
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
			--dbhost="${DB_HOST}" \
			--allow-root

	echo "Install WordPress (creates tables, sets admin credentials)."
	wp core install \
			--path="${WP_PATH}" \
			--url="${DOMAIN_NAME}" \
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

fi


ls -l

exec php-fpm -F
