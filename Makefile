NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find srcs/*.c)
LIBFT_LIB = libft.a

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m

all : $(NAME)

$(LIBFT_LIB) :
	@make bonus -C libft

$(NAME) : $(LIBFT_LIB)
	$(CC) $(CFLAGS) -Iincludes $(SRCS) libft/$(LIBFT_LIB) -o $(NAME)

clean :

fclean :
	@make fclean -C libft
	@rm -f push_swap
	@echo "$(RED)Removed : push_swap.exe"

re :

.PHONY :