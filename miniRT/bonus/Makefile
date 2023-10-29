# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 21:45:52 by eunwolee          #+#    #+#              #
#    Updated: 2023/10/30 07:26:57 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

MLX_NAME = libmlx.dylib
MLX_DIR = mlx

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -rf
MAKE = make

SRCS =	miniRT.c \
		parse/check_valid.c \
		parse/check_valid_type.c \
		parse/set_type.c \
		scene/scene.c \
		scene/img.c \
		scene/cam.c \
		render/mlx.c \
		render/draw.c \
		render/ray.c \
		render/hit.c \
		vector/vec.c \
		vector/cal.c \
		vector/cal2.c \
		vector/unit.c \
		vector/product.c \
		color/color.c \
		light/light.c \
		light/ambient.c \
		light/specular.c \
		light/shadow.c \
		object/sphere.c \
		object/plane.c \
		object/cylinder.c \
		object/cone.c \
		object/util.c \
		list/ft_lstnew.c \
		list/ft_lstadd_back.c \
		list/ft_lstlast.c \
		list/ft_lstsize.c \
		util/util.c

SRCS_WITH_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_WITH_PATH:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

RESET = \033[0m
PINK = \033[38;2;255;170;201m
GREEN = \033[38;2;179;200;144m
YELLOW = \033[38;2;255;231;155m
PECOCK = \033[38;2;115;187;201m
PURPLE = \033[38;2;228;165;255m

NUM_TASK = 11
SIZE = 0
END = 1
GAUGE = WORLD.....🌎
NUM_GAUGE = 11

all:
	@printf "$(GREEN)BUILD $(PECOCK)"
	@$(MAKE) $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	$(eval END = $(shell expr $(END) - 1))
ifneq ($(END),$(NUM_GAUGE))
	$(eval END = $(shell expr $(END) + 1))
	$(eval SIZE = $(shell expr $(NUM_GAUGE) - $(END)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE))))
	@printf "$(PROGRESS)"
endif
	@printf " ready!$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR)
	@cp ./$(MLX_DIR)/$(MLX_NAME) .
	@$(CC) $(MLX_FLAGS) $^ -o $@ -I $(INCS_DIR) -L .

$(L_NAME):
	@$(MAKE) -C $(L_DIR)
	@cp ./$(L_DIR)/$(L_NAME) .
	
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	$(eval SIZE = $(shell expr $(NUM_GAUGE) / $(NUM_TASK)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE) - 1)))
	$(eval END = $(shell expr $(END) + $(SIZE)))
	@printf "$(PROGRESS)"
	@$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS_DIR)

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}/parse
	@mkdir ${OBJS_DIR}/scene
	@mkdir ${OBJS_DIR}/render
	@mkdir ${OBJS_DIR}/vector
	@mkdir ${OBJS_DIR}/color
	@mkdir ${OBJS_DIR}/light
	@mkdir ${OBJS_DIR}/object
	@mkdir ${OBJS_DIR}/list
	@mkdir ${OBJS_DIR}/util

clean:
	@echo "$(YELLOW)CLEANING OBJS... 🧹$(RESET)"
	@$(MAKE) -C $(L_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJS_DIR)
	@$(RM) $(L_NAME)

fclean:
	@echo "$(PINK)CLEANING ALL... 🗑️$(RESET)"
	@$(MAKE) clean
	@$(RM) $(NAME) ./$(INCS_DIR_M)/$(MLX_NAME) ./$(INCS_DIR_B)/$(MLX_NAME)

re:
	@echo "$(PURPLE)RE-BUILD $(NAME)$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re