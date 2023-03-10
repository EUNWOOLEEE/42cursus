# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:21:45 by eunwolee          #+#    #+#              #
#    Updated: 2023/03/09 17:58:03 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

A_NAME = push_swap.a
M_NAME = push_swap
B_NAME = checker

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRC_DIR = source
CMD_DIR = $(SRC_DIR)/command
B_DIR = bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make

M_SRCS = $(SRC_DIR)/push_swap.c \
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

B_SRCS = $(B_DIR)/checker.c \
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

all: $(M_NAME)

$(M_NAME): $(M_SRCS)
	$(MAKE) -C $(L_DIR) all
	cp ./$(L_DIR)/$(L_NAME) $(L_NAME)
	$(CC) $(CFLAGS) $^ $(L_NAME) -I $(INCS_DIR) -o $@

with_bonus: $(B_NAME)

$(B_NAME): $(B_SRCS)
	$(MAKE) -C $(L_DIR) all
	cp ./$(L_DIR)/$(L_NAME) $(L_NAME)
	$(CC) $(CFLAGS) $^ $(L_NAME) -I $(INCS_DIR) -o $@

bonus:
	$(MAKE) all
	$(MAKE) with_bonus

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(RM) $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(M_NAME) $(B_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus with_bonus