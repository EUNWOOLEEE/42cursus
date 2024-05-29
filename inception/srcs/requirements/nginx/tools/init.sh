#!/bin/bash

openssl	req -x509 -nodes -days 365 -newkey rsa:2048							\
		-keyout /etc/ssl/private/nginx-selfsigned.key						\
		-out /etc/ssl/certs/nginx-selfsigned.crt							\
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42seoul/CN=$DOMAIN_NAME"
# 인증기관을 통해 만들지 않고 자체서명을 해서 만든 키와 인증서이기 때문에 nginx-selfsigned.key / .crt 여기에 저장했음

exec nginx -g "daemon off;"
