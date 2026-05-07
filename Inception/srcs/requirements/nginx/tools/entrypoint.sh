#!/bin/bash
set -e

echo "==> NGINX will be launched in port ${NGINX_PORT}"
if [ "${BONUS}" = 1 ]; then
	echo "BONUS MODE: Enabled"
else
	echo "BONUS MODE: Disabled"
fi
sed -i "s/server_name localhost/server_name ${DOMAIN_NAME:-localhost}/" /etc/nginx/nginx.conf
sed -i "s/fastcgi_pass wordpress:9000/fastcgi_pass wordpress:${WP_PORT}/" /etc/nginx/nginx.conf
sed -i "s/listen 443 ssl/listen ${NGINX_PORT} ssl/" /etc/nginx/nginx.conf
sed -i "s/listen \[\:\:\]\:443 ssl/listen \[\:\:\]\:${NGINX_PORT} ssl/" /etc/nginx/nginx.conf

# Test config then start nginx in foreground
nginx -t
nginx -g 'daemon off;'

######## SSL Certification:
# When your browser connects to a server over HTTPS, two things need to happen: the connection must be encrypted, and you need to be able to trust who you're talking to.
# A certificate is a file that contains a public key plus an identity claim (who this key belongs to). The server uses the corresponding private key to prove it actually owns that certificate. That's the pair you're generating: nginx.key (private) and nginx.crt (public certificate).
# Self-signed means: you generated both the certificate and the signature yourself. There's no third party vouching for you. Real certificates are signed by a Certificate Authority (CA) — a trusted organization like Let's Encrypt or DigiCert. When your browser connects to google.com, it checks: "is this certificate signed by someone I trust?" Because your self-signed cert is signed by nobody the browser knows, it will show a security warning. That's expected and acceptable for a local dev project — the encryption still works, the browser just can't verify your identity.
# For Inception, self-signed is correct. Production sites use CA-signed certs (Let's Encrypt being the free standard).
# TLSv1.2 vs TLSv1.3: TLS is the protocol that handles the encrypted handshake and session. 1.0 and 1.1 have known vulnerabilities. The subject requires you to only allow 1.2 and 1.3. This explicitly blocks older, weaker versions.
