FROM debian:bullseye

RUN apt-get update -y &&			\
	apt-get install -y	nginx		\
						openssl

COPY ./tools/init.sh /
COPY ./default /etc/nginx/sites-available/default

RUN chmod -x /init.sh

EXPOSE 443

ENTRYPOINT [ "/bin/bash", "/init.sh" ]