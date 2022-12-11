# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:21:51 by eunwolee          #+#    #+#              #
#    Updated: 2022/12/11 14:50:37 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = includes
SRC_DIR = source

SRCS = $(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_toupper.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_itoa_d.c \
	$(SRC_DIR)/ft_itoa_u.c \
	$(SRC_DIR)/ft_strdup.c


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS_DIR)

clean:
	$(RM) $(OBJS)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
