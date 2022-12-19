# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 13:36:08 by eunwolee          #+#    #+#              #
#    Updated: 2022/12/19 16:04:05 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#libft 변경해도 리링크 안되는거 수정하기

NAME = libftprintf.a

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRC_DIR = source

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f
MAKE = make

SRCS = $(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_print_c.c \
	$(SRC_DIR)/ft_print_s.c \
	$(SRC_DIR)/ft_print_p.c \
	$(SRC_DIR)/ft_print_d.c \
	$(SRC_DIR)/ft_print_u.c \
	$(SRC_DIR)/ft_print_x_low.c \
	$(SRC_DIR)/ft_print_x_up.c \
	$(SRC_DIR)/get_function.c \
	$(SRC_DIR)/get_string.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(L_DIR) all
	cp ./$(L_DIR)/$(L_NAME) $(NAME)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS_DIR)

clean:
	$(MAKE) -C $(L_DIR) clean
	$(RM) $(OBJS)

fclean:
	make clean
	$(MAKE) -C $(L_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re