NAME = pipex

INCS_DIR = includes
SRCS_DIR = srcs

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make

SRCS = $(SRCS_DIR)/philo.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -L . -I $(INCS_DIR) $^ -o $@

clean:
	$(RM) $(SRCS_DIR)/$(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re