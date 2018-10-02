# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcallens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 08:30:21 by tcallens          #+#    #+#              #
#    Updated: 2018/10/02 10:51:45 by tcallens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

INCLUDES = -I ./includes

LIBFT = libft/libft.a

SRCS = ./srcs/main.c\
	  ./srcs/check_flags.c\
	  ./srcs/error.c\
	  ./srcs/utils.c\
	  ./srcs/print.c\
	  ./srcs/ls.c\
	  ./srcs/dir.c\
	  ./srcs/plus.c\
	  ./srcs/sort.c\
	  ./srcs/free_dir.c\
	  ./srcs/range.c\
	  ./srcs/pad.c\
	  ./srcs/print_plus.c\
	  ./srcs/range_plus.c\
	  ./srcs/utils_plus.c\
	

OPTIONS = -Wall -Wextra -Werror

RM = rm -rf

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	@clear
	@make -C libft
	@clear
	@echo "$(GREEN)\t\t\t\t    /|  ---   ---$(reset)"
	@echo "$(RED)\t\t\t\t     | |   | |   |$(reset)"
	@echo "$(RED)\t\t\t\t     |  ---   ---\n$(reset)"
	@echo "$(GREEN)\t\t\t\tlibft has been created.$(RESET)"
	@sleep 1
	@clear
	@echo "$(GREEN)\t\t\t\t    /|  ---   ---$(reset)"
	@echo "$(GREEN)\t\t\t\t     | |   | |   |$(reset)"
	@echo "$(RED)\t\t\t\t     |  ---   ---\n$(reset)"
	@echo "$(BLUE)\t\t\tbeginning of the EXECUTABLE's creation.$(RESET)"
	@sleep 1
	@clear
	@echo "$(GREEN)\t\t\t\t    /|  ---   ---$(reset)"
	@echo "$(GREEN)\t\t\t\t     | |   | |   |$(reset)"
	@echo "$(GREEN)\t\t\t\t     |  ---   ---\n$(reset)"
	@echo "$(GREEN)\t\t\t     --->ft_ls has been built.<---$(RESET)"
	@$(CC) $(SRCS) $(INCLUDES) $(LIBFT) -o $(NAME) $(OPTIONS)

clean:
	@make -C libft fclean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)\t\t\t\tft_ls has been removed.$(RESET)"
	@clear

re: fclean all
