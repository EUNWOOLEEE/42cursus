DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

up:
	${DOCKER_COMPOSE} up -d --build

down:
	${DOCKER_COMPOSE} down

fclean:
	${DOCKER_COMPOSE} down --rmi all --volumes
	rm -rf ./srcs/data/db/*
	rm -rf ./srcs/data/web/*
	# rm -rf /home/eunwolee/data/web/*
	# rm -rf /home/eunwolee/data/db/*

re:	fclean up

.PHONY:	up down fclean re