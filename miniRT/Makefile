# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 21:45:52 by eunwolee          #+#    #+#              #
#    Updated: 2023/09/25 18:13:58 by eunwolee         ###   ########.fr        #
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
		init.c \
		utils.c \
		parse/check_valid.c \
		parse/set_type.c \
		parse/element.c \
		parse/object.c

SRCS_WITH_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_WITH_PATH:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

RESET = \033[0m
PINK = \033[38;2;255;170;201m
GREEN = \033[38;2;179;200;144m
YELLOW = \033[38;2;255;231;155m
PECOCK = \033[38;2;115;187;201m
PURPLE = \033[38;2;228;165;255m

PRE = ✧･ﾟ: *✧･ﾟ:*
NEXT = *:･ﾟ✧*:･ﾟ✧

NUM_TASK = 2
SIZE = 0
END = 1
CHAR = ଘ(੭'꒳')੭━ 
GAUGE = ▁▁▂▂▃▃▅▅▆▆▓▒░✩ 🌟
NUM_GAUGE = 16

all:
	@echo "$(PINK)$(PRE)  BUILD  $(NAME)  $(NEXT)$(RESET)"
	@printf "$(YELLOW)$(CHAR)"
	@$(MAKE) $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	@$(CC) $(MLX_FLAGS) $^ -o $@ -I $(INCS_DIR) -L .
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

clean:
	@echo "$(PECOCK)CLEANING OBJS... 🧹$(RESET)"
	@$(MAKE) -C $(L_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJS_DIR)
	@$(RM) $(L_NAME)

fclean:
	@echo "$(GREEN)CLEANING ALL... 🗑️$(RESET)"
	@$(MAKE) clean
	@$(RM) $(NAME) ./$(INCS_DIR_M)/$(MLX_NAME) ./$(INCS_DIR_B)/$(MLX_NAME)

re:
	@echo "$(PURPLE)$(PRE) RE-BUILD $(NAME) $(NEXT)$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re