#!/bin/bash
# Rule of thumb: anything SECRET or PER-MACHINE (keys, passwords) is created
# here at runtime, never in the Dockerfile at build time.
set -euo pipefail
 
: "${SSH_USER:?SSH_USER missing - copy .env.example to .env}"
: "${SSH_PASSWORD:?SSH_PASSWORD missing - copy .env.example to .env}"

    # anything mounted from the host needs its ownership fixed inside:
# ---------- 1) Onion key folders ----------
# Mounted from the host: give them to the tor user, owner-only access.
for dir in /var/lib/tor/web /var/lib/tor/ssh; do
    chown debian-tor:debian-tor "$dir"
    chmod 700 "$dir"
done

# ---------- 2) SSH host key ----------
HOST_KEY=/etc/ssh/host_keys/ssh_host_ed25519_key
if [ ! -f "$HOST_KEY" ]; then
    ssh-keygen -q -t ed25519 -f "$HOST_KEY" -N ""   # first start only
fi
chown root:root "$HOST_KEY"
chmod 600 "$HOST_KEY"      # otherwise sshd refuses it: "UNPROTECTED PRIVATE KEY FILE"

# ---------- 3) SSH login user ----------
if ! id "$SSH_USER" >/dev/null 2>&1; then
    useradd -m -s /bin/bash "$SSH_USER"
fi
usermod -aG sudo "$SSH_USER"
echo "$SSH_USER:$SSH_PASSWORD" | chpasswd

chown "$SSH_USER:$SSH_USER" "/home/$SSH_USER" "/home/$SSH_USER/.ssh"
chmod 700 "/home/$SSH_USER/.ssh"
if [ -f "/home/$SSH_USER/.ssh/authorized_keys" ]; then
    chown "$SSH_USER:$SSH_USER" "/home/$SSH_USER/.ssh/authorized_keys"
    chmod 600 "/home/$SSH_USER/.ssh/authorized_keys"
fi


# ---------- 4) Start the three services as children of this script ----------
nginx -g 'daemon off;' &            # -g: stay in foreground (we background it)
/usr/sbin/sshd -D -e &              # -D: don't daemonize, -e: log to stderr
tor -f /etc/tor/torrc &
 
# ---------- 5) Supervise ----------
# `wait -n` returns as soon as ANY child exits. We then exit too, and Docker's
# restart policy restarts the whole container (all three services).
wait -n
exit $?
