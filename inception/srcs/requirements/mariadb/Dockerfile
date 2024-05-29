FROM debian:bullseye

RUN apt-get update -y &&				\
	apt-get upgrade -y &&				\
	apt-get install -y mariadb-server

COPY ./tools/init.sh /
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chmod +x /init.sh

EXPOSE 3306

RUN chown -R mysql:mysql /etc/mysql/mariadb.conf.d
RUN chmod -R 755 /etc/mysql/mariadb.conf.d

RUN chown -R mysql:mysql /var/log /var/run /var/lib/mysql
RUN chmod -R 755 /var/log /var/run /var/lib/mysql

ENTRYPOINT [ "/bin/bash", "/init.sh" ]