#!/bin/bash

openssl	req -x509 -nodes -days 365 -newkey rsa:2048							\
		-keyout /etc/ssl/private/nginx-selfsigned.key						\
		-out /etc/ssl/certs/nginx-selfsigned.crt							\
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42seoul/CN=$DOMAIN_NAME"

exec nginx -g "daemon off;"
