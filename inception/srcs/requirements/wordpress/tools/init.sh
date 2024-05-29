#!/bin/bash

sleep 5 # 데이터베이스 생성 대기

mkdir -p /var/www/html
cd /var/www/html # root에서 home으로 이동

#wp
wp core download --allow-root
wp config create --dbname=$MARIADB_NAME --dbuser=$MARIADB_USER_NAME --dbpass=$MARIADB_USER_PASSWORD --dbhost=$WP_DB_HOST --allow-root
wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
wp user create $WP_USER_NAME $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=author --allow-root

#php
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.4/fpm/pool.d/www.conf
mkdir /run/php # php-fpm이 소켓 파일을 생성하는 디렉토리. 처음에 없을 수도 있음

exec php-fpm7.4 -F
