# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:21:51 by eunwolee          #+#    #+#              #
#    Updated: 2023/03/28 20:07:14 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_memset.c \
	ft_memmove.c \
	ft_calloc.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstnew.c \
	ft_lstlast.c \
	get_next_line.c \
	get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I .

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
