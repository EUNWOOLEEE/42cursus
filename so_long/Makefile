# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 20:21:25 by eunwolee          #+#    #+#              #
#    Updated: 2023/04/04 20:10:33 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_NAME = libmlx.dylib
MLX_DIR = mlx

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes

SRC_DIR_M = source_m
SRC_DIR_B = source_b

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f
MAKE = make

SRCS_M = $(SRC_DIR_M)/so_long.c \
	$(SRC_DIR_M)/game_start.c \
	$(SRC_DIR_M)/game_end.c \
	$(SRC_DIR_M)/init_map.c \
	$(SRC_DIR_M)/init_img.c \
	$(SRC_DIR_M)/init_img_c.c \
	$(SRC_DIR_M)/check_valid.c \
	$(SRC_DIR_M)/check_route.c \
	$(SRC_DIR_M)/draw.c \
	$(SRC_DIR_M)/get_hook.c \
	$(SRC_DIR_M)/stand.c \
	$(SRC_DIR_M)/move.c \
	$(SRC_DIR_M)/move_walk.c \
	$(SRC_DIR_M)/move_jump.c \
	$(SRC_DIR_M)/utils.c

SRCS_B = $(SRC_DIR_B)/so_long_bonus.c \
	$(SRC_DIR_B)/game_start_bonus.c \
	$(SRC_DIR_B)/game_end_bonus.c \
	$(SRC_DIR_B)/init_map_bonus.c \
	$(SRC_DIR_B)/init_hole_bonus.c \
	$(SRC_DIR_B)/init_img_bonus.c \
	$(SRC_DIR_B)/init_img_c_bonus.c \
	$(SRC_DIR_B)/check_valid_bonus.c \
	$(SRC_DIR_B)/check_route_bonus.c \
	$(SRC_DIR_B)/draw_bonus.c \
	$(SRC_DIR_B)/get_hook_bonus.c \
	$(SRC_DIR_B)/stand_bonus.c \
	$(SRC_DIR_B)/move_bonus.c \
	$(SRC_DIR_B)/move_walk_bonus.c \
	$(SRC_DIR_B)/move_jump_bonus.c \
	$(SRC_DIR_B)/utils_bonus.c

ifdef WITH_BONUS
	OBJS = $(SRCS_B:%.c=%.o)
else
	OBJS = $(SRCS_M:%.c=%.o)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(MLX_DIR)

all:
	$(RM) ./$(SRC_DIR_B)/*.o
	$(MAKE) $(NAME)

bonus:
	$(RM) ./$(SRC_DIR_M)/*.o
	$(MAKE) WITH_BONUS=1 $(NAME)

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
	$(RM) $(SRC_DIR_M)/*.o $(SRC_DIR_B)/*.o $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME) ./$(INCS_DIR_M)/$(MLX_NAME) ./$(INCS_DIR_B)/$(MLX_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus