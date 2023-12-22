# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 22:47:37 by eunwolee          #+#    #+#              #
#    Updated: 2023/12/22 18:30:48 by eunwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_DIR = srcs
OBJS_DIR = objs

RM = rm -rf
MAKE = make

SRCS =	core/main.cpp \
		core/conf.cpp \
		core/cmd.cpp \
		core/conf_cmd.cpp \
		core/cycle.cpp \
		core/server.cpp \
		core/location.cpp \
		core/exception.cpp

SRCS_WITH_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_WITH_PATH:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

RESET = \033[0m
PINK = \033[38;2;255;170;201m
GREEN = \033[38;2;179;200;144m
YELLOW = \033[38;2;255;231;155m
PECOCK = \033[38;2;115;187;201m
PURPLE = \033[38;2;228;165;255m

NUM_TASK = 5
SIZE = 0
END = 1
CHAR = ""
GAUGE = 🎋...... 🐼=3 yummy!
NUM_GAUGE = 18

all:
	@echo "$(PINK)BUILD $(NAME)$(RESET)"
	@printf "$(YELLOW)$(CHAR)"
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	$(eval END = $(shell expr $(END) - 1))
ifneq ($(END),$(NUM_GAUGE))
	$(eval END = $(shell expr $(END) + 1))
	$(eval SIZE = $(shell expr $(NUM_GAUGE) - $(END)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE))))
	@printf "$(PROGRESS)"
endif
	@printf " ready!$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(eval SIZE = $(shell expr $(NUM_GAUGE) / $(NUM_TASK)))
	$(eval PROGRESS = $(shell echo "$(GAUGE)" | cut -c $(END)-$(shell expr $(END) + $(SIZE) - 1)))
	$(eval END = $(shell expr $(END) + $(SIZE)))
	@printf "$(PROGRESS)"
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}/core

clean:
	@echo "$(PECOCK)CLEANING OBJS... 🧹$(RESET)"
	@$(RM) $(OBJS_DIR)

fclean:
	@echo "$(GREEN)CLEANING ALL... 🗑️$(RESET)"
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@echo "$(PURPLE)RE-BUILD $(NAME)$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re