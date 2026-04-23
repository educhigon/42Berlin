#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"

mkdir -p /var/www/html
cd /var/www/html

echo "Folder html created at: "
wget https://wordpress.org/latest.tar.gz
tar -xzf latest.tar.gz --strip-components=1
rm latest.tar.gz

echo "creating wp-config.php:"

cat << EOF >> wp-config.php
<?php
define('DB_NAME', '${DB_NAME}');
define('DB_USER', '${DB_USER}');
define('DB_PASSWORD', '${DB_PASSWORD}');
define('DB_HOST', '${DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

\$table_prefix = '${WORDPRESS_TABLE_PREFIX:-wp_}';

${WP_SALTS}

define('WP_DEBUG', false);

if ( !defined('ABSPATH') )
    define('ABSPATH', __DIR__ . '/');

require_once ABSPATH . 'wp-settings.php';
EOF

echo "wp-config.php CREATED"
exec php-fpm -F
