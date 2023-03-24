# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 20:21:25 by eunwolee          #+#    #+#              #
#    Updated: 2023/03/24 21:57:31 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#수정하기
MLX_NAME = libmlx.dylib
MLX_DIR = mlx_mac

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRC_DIR = source

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f
MAKE = make

SRCS = $(SRC_DIR)/so_long.c \
	$(SRC_DIR)/map_init.c \
	$(SRC_DIR)/img_init.c \
	$(SRC_DIR)/check_valid.c \
	$(SRC_DIR)/bfs.c \
	$(SRC_DIR)/create_game.c \
	$(SRC_DIR)/draw.c \
	$(SRC_DIR)/get_hook.c \
	$(SRC_DIR)/move.c \
	$(SRC_DIR)/move_walk.c \
	$(SRC_DIR)/move_jump.c \
	$(SRC_DIR)/utils.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	cp ./$(MLX_DIR)/$(MLX_NAME) .
	$(CC) $(MLX_FLAGS) -L . $^ -o $@

$(L_NAME):
	$(MAKE) -C $(L_DIR)
	cp ./$(L_DIR)/$(L_NAME) .

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(L_NAME) $(MLX_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re