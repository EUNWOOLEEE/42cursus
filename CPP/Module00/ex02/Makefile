# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 06:43:20 by eunwolee          #+#    #+#              #
#    Updated: 2023/08/07 10:09:26 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = g++

RM = rm -f
MAKE = make

SRCS = ./phonebook.cpp \
	./pb_add.cpp \
	./pb_search.cpp \
	./pb_exit.cpp

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.c
	$(CC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

clean:
	$(RM) ${OBJS}

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re