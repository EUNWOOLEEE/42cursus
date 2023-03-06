# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:21:45 by eunwolee          #+#    #+#              #
#    Updated: 2023/03/06 19:02:58 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRC_DIR = source
CMD_DIR = $(SRC_DIR)/command

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make

SRCS = $(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/solve.c \
	$(SRC_DIR)/a_to_b.c \
	$(SRC_DIR)/b_to_a.c \
	$(SRC_DIR)/under_five.c \
	$(CMD_DIR)/push.c \
	$(CMD_DIR)/swap.c \
	$(CMD_DIR)/rotate.c \
	$(CMD_DIR)/r_rotate.c

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C $(L_DIR) all
	cp ./$(L_DIR)/$(L_NAME) $(L_NAME)
	$(CC) $(CFLAGS) $^ $(L_NAME) -I $(INCS_DIR) -o $(NAME)

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(RM) $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re