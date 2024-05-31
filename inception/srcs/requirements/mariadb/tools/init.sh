#!/bin/bash

service mariadb start

sleep 2

mysql -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD( '$MARIADB_ROOT_PASSWORD' );"
mysql -e "CREATE DATABASE IF NOT EXISTS $MARIADB_NAME;"
mysql -e "CREATE USER IF NOT EXISTS '$MARIADB_USER_NAME'@'%' IDENTIFIED BY '$MARIADB_USER_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON $MARIADB_NAME.* TO '$MARIADB_USER_NAME'@'%';"
mysql -e "FLUSH PRIVILEGES;"

service mariadb stop

exec mariadbd
