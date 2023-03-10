# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:21:51 by eunwolee          #+#    #+#              #
#    Updated: 2023/03/10 22:10:12 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCS_DIR = includes
SRC_DIR = source

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRCS = $(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_cnt_digit.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/get_next_line_utils.c \
	$(SRC_DIR)/ft_lstadd_back.c \
	$(SRC_DIR)/ft_lstclear.c \
	$(SRC_DIR)/ft_lstdelone.c \
	$(SRC_DIR)/ft_lstsize.c \
	$(SRC_DIR)/ft_lstlast.c \
	$(SRC_DIR)/ft_lstnew.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
