# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 22:47:37 by eunwolee          #+#    #+#              #
#    Updated: 2023/09/13 20:59:35 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f
MAKE = make

SRCS = ./megaphone.cpp

OBJS = $(SRCS:%.cpp=%.o)

RESET = \033[0m
PINK = \033[38;2;255;170;201m
GREEN = \033[38;2;179;200;144m
YELLOW = \033[38;2;255;231;155m
PECOCK = \033[38;2;115;187;201m
PURPLE = \033[38;2;228;165;255m

PRE = ✧･ﾟ: *✧･ﾟ:*
NEXT = *:･ﾟ✧*:･ﾟ✧

NUM_TASK = 1
SIZE = 0
CHAR = ଘ(੭'꒳')੭━ 
GAUGE = ▁▁▂▂▃▃▅▅▆▆▓▒░✩ 🌟
NUM_GAUGE = 16
END = 1

all:
	@echo "$(PINK)$(PRE)  BUILD  $(NAME)  $(NEXT)$(RESET)"
	@printf "$(YELLOW)$(CHAR)"
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ -I .
	$(eval END = $(shell expr $(END) - 1))
ifneq ($(END),$(NUM_GAUGE))
	$(eval END = $(shell expr $(END) + 1))
	$(eval SIZE = $(shell expr $(NUM_GAUGE) - $(END)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE))))
	@printf "$(PROGRESS)"
endif
	@printf " ready!$(RESET)\n"

%.o: %.cpp
	$(eval SIZE = $(shell expr $(NUM_GAUGE) / $(NUM_TASK)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE) - 1)))
	$(eval END = $(shell expr $(END) + $(SIZE)))
	@printf "$(PROGRESS)"
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@echo "$(PECOCK)CLEANING OBJS... 🧹$(RESET)"
	@$(RM) $(OBJS)

fclean:
	@echo "$(GREEN)CLEANING ALL... 🗑️$(RESET)"
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@echo "$(PURPLE)$(PRE) RE-BUILD $(NAME) $(NEXT)$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re