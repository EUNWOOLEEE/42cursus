# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 12:26:07 by eunwolee          #+#    #+#              #
#    Updated: 2023/04/06 20:07:59 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRC_DIR = source

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f
MAKE = make

SRCS = $(SRC_DIR)/pipex.c \
	# $(SRC_DIR)/parsing.c \

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

all: $(NAME)

# bonus:
# 	$(RM) ./$(SRC_DIR)/*.o
# 	$(MAKE) WITH_BONUS=1 $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	$(CC) -L . -I $(INCS_DIR) $^ -o $@

$(L_NAME):
	$(MAKE) -C $(L_DIR)
	cp ./$(L_DIR)/$(L_NAME) .

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(RM) $(SRC_DIR)/*.o $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus