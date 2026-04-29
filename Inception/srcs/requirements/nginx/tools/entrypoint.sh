#!/bin/bash
set -e

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

echo "==> NGINX will be launched in port ${NGINX_PORT}"
sed -i "s/fastcgi_pass wordpress:9000/fastcgi_pass wordpress:${WP_PORT}/" /etc/nginx/nginx.conf
sed -i "s/listen 443 ssl/listen ${NGINX_PORT} ssl/" /etc/nginx/nginx.conf
sed -i "s/listen \[\:\:\]\:443 ssl/listen \[\:\:\]\:${NGINX_PORT} ssl/" /etc/nginx/nginx.conf

# Test config then start nginx in foreground
nginx -t
nginx -g 'daemon off;'
# &

# # Tail logs to stdout (replace shell with tail so it receives signals)
# exec tail -F /var/log/nginx/access.log /var/log/nginx/error.log


######## SSL Certification:
# When your browser connects to a server over HTTPS, two things need to happen: the connection must be encrypted, and you need to be able to trust who you're talking to.
# A certificate is a file that contains a public key plus an identity claim (who this key belongs to). The server uses the corresponding private key to prove it actually owns that certificate. That's the pair you're generating: nginx.key (private) and nginx.crt (public certificate).
# Self-signed means: you generated both the certificate and the signature yourself. There's no third party vouching for you. Real certificates are signed by a Certificate Authority (CA) — a trusted organization like Let's Encrypt or DigiCert. When your browser connects to google.com, it checks: "is this certificate signed by someone I trust?" Because your self-signed cert is signed by nobody the browser knows, it will show a security warning. That's expected and acceptable for a local dev project — the encryption still works, the browser just can't verify your identity.
# For Inception, self-signed is correct. Production sites use CA-signed certs (Let's Encrypt being the free standard).
# TLSv1.2 vs TLSv1.3: TLS is the protocol that handles the encrypted handshake and session. 1.0 and 1.1 have known vulnerabilities. The subject requires you to only allow 1.2 and 1.3. This explicitly blocks older, weaker versions.
