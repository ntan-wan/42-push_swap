NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find srcs/*.c)

all : $(NAME)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :

fclean :

re :

.PHONY :