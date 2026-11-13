Makefile:
	On startup we create and export the folder that will contain the key. Nothing happens if the folder already exists

```
	ONION_KEYS_DIR ?= $(HOME)/.ft_onion
	export ONION_KEYS_DIR
```

docker-compose:
	Only container configuration.
	Volume configuration is done in the Makefile, outside the container with root priviledges
	The container has no network - no connection to any outside work
	Even though we are using NGINx, we don't open any port for the container to communicate with the host

Dockerfile:
	We install *tor*, *nginx* and *sshd*
	Additionally, we also install *iproute2* for convenience: `make check` uses `ss`
	- Every time you install SSH it automatically generates an SSH key. We need to delete that because the container will save the key on it's image and that is a breach of security (the same key will be used multiple times)
	- We create an empty run/sshd because each client forks a child that handles the login and then drops to that user’s privileges.

torrc:
	SocksPort 0: the server only publishes onion services and never acts as a Tor client (9050), so the proxy is disabled. That means one less listener, and a compromised process can’t use it as an anonymous way out.
	- Tor Browser contains its own Tor client. While it’s open, that client listens on 127.0.0.1:9150.
	- A system-wide tor service uses 9050 instead. That’s the port your server’s SocksPort 0 disabled. Tor Browser uses a different port on purpose, so both can run on the same machine.

nginx.conf:
    server_tokens off -> Stop advertising the nginx version in response headers and error pages.
		- Known exploits: a version number tells an attacker exactly which known vulnerabilities to try. That’s true for any website.
		- Fingerprinting: an onion service’s whole security rests on not leaking anything that identifies the real server. Recall section 5 of the lecture: most deanonymizations are application-level leaks, not breaks in Tor. Details like the exact nginx version are fingerprints. An investigator can scan the normal internet for a server with the same version and the same quirks, and narrow down who you are.
		- Honest limit: nginx still sends Server: nginx, just without the version. Hiding even that needs an extra module. It’s worth knowing so you’re not caught off guard if asked.

    listen 127.0.0.1:80 -> linstenning on loopback only, otherwise the port is open
		It’s not just a declaration. There is a network, and our container can’t work without one.

		Why there’s always a network:

		tor needs to reach the internet, so the container must have a network interface.
		Compose automatically creates a network for the project (ft_onion_default) and gives the container an address on it, e.g. 172.18.0.2, behind the host’s NAT. That’s the outbound path we discussed.
		The only way to have no network is network_mode: none, and then tor couldn’t reach any relay.

		So with listen 80;, nginx also answers on that 172.18.0.2 interface.

		Who can actually reach that address:

		The host itself. On a Linux host, the host can connect to container IPs directly, no -p needed. On Docker Desktop for Mac it can’t, because containers live inside a hidden VM. So the exposure depends on the machine you defend on, and that alone is a reason not to rely on it.
		Any other container you, or a future you, attach to that network.

		Both paths bypass Tor completely.

		Proving: On a Linux host, temporarily set listen 80;, then from the host run:

		curl http://$(docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' ft_onion)

		You’ll get your page, without any published port. Switch back to 127.0.0.1:80 and the same command gets “connection refused”. That’s a nice live demo of why loopback matters.

sshd_config
	PermitRootLogin no. 
	- You log in as a normal user and escalate only when needed, with sudo or su. Reasons to forbid direct root login:
	- Every server has an account called root, so an attacker already knows half the credentials and only has to guess the password. With evaluator, they’d have to guess the username too.
	- Least privilege: a stolen user session isn’t automatically full control of the machine.
	- Accountability: on a server with several admins, “root logged in” tells you nothing about who it was.

# Tests

`make address`
web: webaddress.onion
ssh: sshaddress.onion

Setup:
1. Check connectivity: Tor Browser → http://webaddress.onion
2. Check connectivity: `curl -x socks5h://test1:x@127.0.0.1:9150 http://webaddress.onion`
4. Only NGINx serves the web: `docker exec ft_onion ps aux`
5. No published ports: `make check`

6. Check access to the server via SSH: `make ssh`
6. 1. ssh as user -> `sudo whoami` -> root
6. 2. config files are valid
	`sudo nginx -t`   # → syntax is ok / test is successful
	`sudo sshd -t`    # → no output = OK
6. 3. loopback open, network interface closed
	`IP=$(hostname -I | awk '{print $1}'); echo $IP`
    `echo > /dev/tcp/127.0.0.1/80`   #--> No response = port open
    `echo > /dev/tcp/$IP/80`         #--> Connection refused
    `echo > /dev/tcp/127.0.0.1/4242` #--> No response = port open
    `echo > /dev/tcp/$IP/4242`       #--> Connection refused
6. 4. The onion keys are off-limits to the login user
	`cat /var/lib/tor/web/hs_ed25519_secret_key`    # → Permission denied
	`sudo ls -ld /var/lib/tor/web /var/lib/tor/ssh` # → drwx------ debian-tor
6. 5. And the user's own SSH files have the modes StrictModes demands
	`ls -ld ~/.ssh` # → drwx------ evaluator

Security checks:
7. `ssh -o ProxyCommand='nc -X 5 -x 127.0.0.1:9150 %h %p' -p 4242 root@sshaddress.onion` --> Permission denied
8. NGINx version: `curl -sI --socks5-hostname 127.0.0.1:9150 http://webaddress.onion | grep -i server` --> no version
9. No hosts keys in the container: `docker run --rm --entrypoint ls ft_onion-ft_onion /etc/ssh` --> no ssh_host_* files

Idempotency:
10. ONION address survival: `make address` - then `make re` and `make address` --> addresses are the same
11. SSH identity survival: connect SSH, `make re` and connect SSH again --> no errors
	show fingerprint before and after: `docker exec ft_onion ssh-keygen -lf /etc/ssh/host_keys/ssh_host_ed25519_key.pub`
12. Self-healing (kill nignx and the containers come back up): `docker exec ft_onion pkill nginx` then `docker ps` --> everything restarts cleanly
13. key login: `make keygen` -> `make add-key` -> `make ssh`, then ssh --> log in without password




