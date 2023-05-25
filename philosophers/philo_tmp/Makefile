NAME = philo

INCS_DIR = incs
SRCS_DIR = srcs

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make

SRCS = $(SRCS_DIR)/philo.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/start.c \
	$(SRCS_DIR)/act.c \
	$(SRCS_DIR)/utils.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -I $(INCS_DIR) $^ -o $@

clean:
	$(RM) $(SRCS_DIR)/$(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re