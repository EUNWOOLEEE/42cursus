FROM debian:bullseye

RUN apt-get update -y &&			\
	apt-get install -y	nginx		\
						openssl

COPY ./tools/init.sh /
COPY ./default /etc/nginx/sites-available/default

RUN chmod -x /init.sh

EXPOSE 443
# 이 컨테이너에서 443포트를 사용할 수 있도록 함

ENTRYPOINT [ "/bin/bash", "/init.sh" ]