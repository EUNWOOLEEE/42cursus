# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 12:26:07 by eunwolee          #+#    #+#              #
#    Updated: 2023/04/28 13:12:50 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes
SRCS_DIR_M = srcs_m
SRCS_DIR_B = srcs_b

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make

SRCS_M = $(SRCS_DIR_M)/pipex.c \
	$(SRCS_DIR_M)/init.c \
	$(SRCS_DIR_M)/quote.c \
	$(SRCS_DIR_M)/execute.c \
	$(SRCS_DIR_M)/pipe.c \
	$(SRCS_DIR_M)/utils.c \

SRCS_B = $(SRCS_DIR_B)/pipex_bonus.c \
	$(SRCS_DIR_B)/init_bonus.c \
	$(SRCS_DIR_B)/quote_bonus.c \
	$(SRCS_DIR_B)/heredoc_bonus.c \
	$(SRCS_DIR_B)/execute_bonus.c \
	$(SRCS_DIR_B)/pipe_bonus.c \
	$(SRCS_DIR_B)/utils_bonus.c \

ifdef WITH_BONUS
	OBJS = $(SRCS_B:%.c=%.o)
else
	OBJS = $(SRCS_M:%.c=%.o)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

all:
	$(RM) ./$(SRCS_DIR_B)/*.o
	$(MAKE) $(NAME)

bonus:
	$(RM) ./$(SRCS_DIR_M)/*.o
	$(MAKE) WITH_BONUS=1 $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	$(CC) -L . -I $(INCS_DIR) $^ -o $@

$(L_NAME):
	$(MAKE) -C $(L_DIR)
	cp ./$(L_DIR)/$(L_NAME) .

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(RM) $(SRCS_DIR_M)/*.o $(SRCS_DIR_B)/*.o $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus