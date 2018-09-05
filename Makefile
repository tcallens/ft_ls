NAME=ft_ls
CC=gcc
INCLUDES= -I ./includes
LIBFT= libft/libft.a
SRCS= ./srcs/main.c\
	  ./srcs/check_flags.c\
	  ./srcs/error.c\
	

OPTIONS= -Wall -Wextra -Werror
RM= rm -rf

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m

name:
	@make -C libft
	@$(CC) $(SRCS) $(INCLUDES) $(LIBFT) -o $(NAME) $(OPTIONS)
	@echo "$(BLUE)\t\t\t\tft_ls has been built.$(RESET)"

clean:
	@make -C libft fclean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)\t\t\t\tft_ls has been removed.$(RESET)"

re: fclean all

all: name
