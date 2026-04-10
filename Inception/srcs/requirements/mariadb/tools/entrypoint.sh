#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password 2>/dev/null)";
DB_PASSWORD="${DB_PASSWORD:-1234}"

DB_ADMIN_PASSWORD="$(cat /run/secrets/db_admin_password 2>/dev/null)";
DB_ADMIN_PASSWORD="${DB_ADMIN_PASSWORD:-1234}"

DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password 2>/dev/null)";
DB_ROOT_PASSWORD="${DB_ROOT_PASSWORD:-1234}"

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

if [ ! -d "/var/lib/mysql/mysql" ]; then
	# echo
	# echo Databse name : "$DB_NAME"
	# echo
	# echo root password: "$DB_ROOT_PASSWORD"
	# echo
	# echo user name : "$DB_USER"
	# echo user password: "$DB_PASSWORD"
	# echo
	# echo admin name : "$DB_ADMIN"
	# echo admin password: "$DB_ADMIN_PASSWORD"
	# echo
	# echo
	mysql_install_db --user=mysql --datadir=/var/lib/mysql

	mysqld --user=mysql --bootstrap << EOF

FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS ${DB_NAME};

CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';

CREATE USER IF NOT EXISTS '${DB_ADMIN}'@'%' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO '${DB_ADMIN}'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;

EOF
fi

exec mysqld --user=mysql



#  #!/bin/bash
#   Tells the OS which interpreter to use to run this file. Without this, the kernel doesn't know if this is bash, sh, python, etc.

#   ---
#   set -e
#   If any command in the script returns a non-zero exit code (failure), stop immediately. Without this, the script would continue past errors silently,
#   potentially leaving the database in a broken half-initialized state. Always use this in entrypoint scripts.

#   ---
#   DB_PASSWORD=$(cat /run/secrets/db_password)
#   DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

#   Docker Secrets — when you declare secrets in docker-compose, Docker mounts them as files inside /run/secrets/. This reads those files and stores the
#   content in shell variables. This is safer than passing passwords as environment variables, which are visible to anyone who runs docker inspect.

#   ---
#   if [ ! -d "/var/lib/mysql/mysql" ]

#   This is the most important line conceptually. It asks: does the internal mysql directory exist inside the data directory? MariaDB creates this directory
#   the first time it initializes — it contains its own system tables.

#   The logic: only initialize if this is a fresh start. If the directory already exists, the database was already initialized on a previous run and we skip
#   everything. This is what makes the entrypoint idempotent — safe to run multiple times without corrupting existing data. Without this check, every
#   container restart would wipe and reinitialize your database.

#   ---
#   mysql_install_db --user=mysql --datadir=/var/lib/mysql

#   Initializes a fresh MariaDB data directory — creates the system tables, the mysql internal database, permission structures. This is a one-time setup that
#   must happen before MariaDB can run for the first time. --user=mysql means the files are owned by the mysql system user (not root), which is the secure
#   default MariaDB expects.

#   ---
#   mysqld --user=mysql --bootstrap << EOF

#   This starts MariaDB in bootstrap mode — a special minimal mode that accepts SQL commands on stdin and exits when done. It's not a real server, it accepts
#   no connections. You use it to run setup SQL before the real server starts.

#   << EOF is a bash heredoc — everything between << EOF and EOF is piped as stdin to the command.

#   ---
#   FLUSH PRIVILEGES;
#   Tells MariaDB to reload its permission tables from disk. Good practice before and after making permission changes.

#   ---
#   ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
#   Sets the root password. The base MariaDB image has no root password by default — this secures it.

#   ---
#   CREATE DATABASE IF NOT EXISTS ${DB_NAME};
#   Creates your application database. IF NOT EXISTS is a safety guard, though the if block above already ensures this only runs once.

#   ---
#   CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
#   Creates a non-root user for your application (WordPress will use this). The '%' means "from any host" — necessary because WordPress runs in a different
#   container, so its connection comes from a different IP.

#   ---
#   GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
#   Gives that user full access to your application database only. Not to everything — just ${DB_NAME}.*.

#   ---
#   FLUSH PRIVILEGES;
#   Reloads permissions so the grants take effect immediately.

#   ---
#   exec mysqld --user=mysql


# Every service entrypoint follows the same pattern:

#   1. Read any secrets or config you need at runtime
#   2. Check if this is a first run — look for a file/directory that only exists after initialization
#   3. If first run: initialize — create data structures, set passwords, seed databases
#   4. exec the actual service as the last line — this becomes PID 1 and runs until the container stops

#   Ask yourself for each service:
#   - Does this service have persistent state that needs initializing once?
#   - What process needs to be running for the service to be "up"?
#   - What configuration does it need that only exists at runtime (secrets, env vars, other services' addresses)?
#   - Does it need to wait for another service to be ready before starting? (WordPress needs MariaDB to be up first)

#   That last point — dependency ordering — is something you'll need to handle in WordPress's entrypoint. MariaDB takes a moment to be ready after its
#   container starts, and WordPress will fail if it tries to connect before that.
