FROM debian:bullseye

RUN apt-get update -y &&				\
	apt-get upgrade -y &&				\
	apt-get install -y	php				\
						php-fpm			\
						php-mysql		\
						curl			\
						mariadb-client	\
						php-cli
						# 기본적으로 php7.4로 설치됨

COPY ./tools/init.sh /

RUN chmod +x /init.sh

EXPOSE 9000

# 원격 위치에 있는 wp-cli.phar을 다운로드
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&	\
	chmod +x wp-cli.phar &&																	\
	mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT [ "/bin/bash", "/init.sh" ]