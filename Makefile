NAME =push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_DIR = includes/
SRCS_DIR =  srcs/
SRCS = $(shell find srcs/*.c)
OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
LIBFT_DIR = libft/
LIBFT_LIB = libft.a

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m
MAGNETA=\033[95m
all : $(NAME)

$(LIBFT_LIB) :
	@make bonus -C libft

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC)  -c $< -o $@ -I$(HEADER_DIR)
	@echo "$(CYAN)Compiling : $<"

$(NAME) : $(LIBFT_LIB) $(OBJS_PREFIXED)
	@$(CC) $(OBJS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)push_swap.exe Done!$(COLOR_OFF)"
clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removed : objs file (push_swap)$(COLOR_OFF)"

fclean : clean
	@make fclean -C libft
	@rm -f push_swap
	@echo "$(RED)Removed : push_swap.exe$(COLOR_OFF)"

re : fclean all

.PHONY : all clean fclean re