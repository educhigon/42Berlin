	- How to create a Dockerfile:
		1. Identify the process that runs
		2. Go to that application's documentation (not Docker's) to find its requirements
		3. Work backwards from requirements to packages
		4. The entrypoint handles what can't be done at build time

		Before writing a single line of code for each container, answer:

			1. What process runs at the end? (mysqld / php-fpm / nginx)
			2. What does that process need installed? (packages)
			3. What files does it need that don't come from packages? (WordPress files, config files)
			4. Who creates those files and when? (build time in Dockerfile, or runtime in entrypoint)
			5. What other services does it depend on?
			6. What volumes does it share with other containers?

  ---
  The network question you couldn't explain

  Every process that listens for connections binds to an address:port. The address controls who can connect.

  127.0.0.1 means "only accept connections from this same machine". It's the loopback address — traffic sent here never leaves the machine. Safe for
  local-only communication.

  0.0.0.0 means "accept connections on any network interface". Any machine that can reach this machine on the network can connect.

  In Docker, each container is a separate machine from the network's perspective. When php-fpm binds to 127.0.0.1:9000, nginx in another container tries to
  connect and gets rejected — different machine. When php-fpm binds to 0.0.0.0:9000, nginx can reach it over the Docker network. This has nothing to do with
   Docker specifically — it's how every networked process works on any OS.

  ---
  What PHP actually is in this context

  PHP is a language that runs on a server and generates HTML. When you visit a WordPress page, you're not downloading a pre-written HTML file. You're
  triggering a PHP program that queries the database, builds the page dynamically, and returns HTML to your browser.

  PHP can run in two modes:
  - CLI: you run a script directly, it executes and exits. Like running a C binary.
  - FPM (FastCGI Process Manager): a long-running process that waits for requests to execute PHP files, executes them, and returns the output. This is what
  you need for a web server.

  php-fpm is not part of WordPress. It's the engine that executes WordPress's PHP files on demand.

  ---
  What WordPress actually is

  WordPress is a content management system — a pre-written PHP application. When you download WordPress you get a folder of .php files that together
  implement a website: user login, page rendering, admin panel, database queries, everything.

  You don't write WordPress. You deploy it. Your job is to put those files somewhere php-fpm can execute them, and give it a wp-config.php that tells it
  where the database is.

  The relationship:

  nginx receives HTTP request for a page
    → passes it to php-fpm
      → php-fpm executes the relevant WordPress .php file
        → that file queries MariaDB for content
          → builds HTML
            → returns to php-fpm
              → returns to nginx
                → returns to browser

  ---
  What each file in your project is responsible for

  Dockerfile: build time only. Install packages, copy files into the image, set permissions. No runtime logic here.

  entrypoint.sh: runtime initialization. Everything that needs to happen before the main process starts — and things that depend on environment variables,
  secrets, or other containers that don't exist at build time.

  conf/ files: configuration for the service. Copied in by the Dockerfile, they configure how the process behaves when it runs.

  The rule of thumb:
  - Needs to happen once when building the image → Dockerfile
  - Needs to happen on first run or every run → entrypoint
  - Controls how the service behaves → conf file
