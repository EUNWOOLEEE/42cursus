# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 22:47:37 by eunwolee          #+#    #+#              #
#    Updated: 2023/08/07 06:41:21 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = g++

RM = rm -f
MAKE = make

SRCS = ./megaphone.c

OBJS = $(SRCS:%.c=%.o)

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