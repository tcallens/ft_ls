# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcallens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 21:18:59 by tcallens          #+#    #+#              #
#    Updated: 2017/11/22 01:03:26 by tcallens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC =\
	 ft_atoi.c\
	 ft_bzero.c\
	 ft_isalnum.c\
	 ft_isalpha.c\
	 ft_isascii.c\
	 ft_isdigit.c\
	 ft_isprint.c\
	 ft_itoa.c\
	 ft_memalloc.c\
	 ft_memccpy.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_memcpy.c\
	 ft_memdel.c\
	 ft_memmove.c\
	 ft_memset.c\
	 ft_putchar.c\
	 ft_putchar_fd.c\
	 ft_putendl.c\
	 ft_putendl_fd.c\
	 ft_putnbr.c\
	 ft_putnbr_fd.c\
	 ft_putstr.c\
	 ft_putstr_fd.c\
	 ft_strcat.c\
	 ft_strchr.c\
	 ft_strclr.c\
	 ft_strcmp.c\
	 ft_strcpy.c\
	 ft_strdel.c\
	 ft_strdup.c\
	 ft_strequ.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strjoin.c\
	 ft_strlcat.c\
	 ft_strlen.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strncat.c\
	 ft_strncmp.c\
	 ft_strncpy.c\
	 ft_strnequ.c\
	 ft_strnew.c\
	 ft_strnstr.c\
	 ft_strrchr.c\
	 ft_strsplit.c\
	 ft_strstr.c\
	 ft_strtrim.c\
	 ft_tolower.c\
	 ft_strsub.c\
	 ft_toupper.c\
	 ft_lstnew.c\
	 ft_lstdelone.c\
	 ft_lstdel.c\
	 ft_lstiter.c\
	 ft_lstmap.c\
	 ft_lstadd.c\
	 ft_intendl.c\
	 ft_countwords.c\
	 ft_wordlen.c\
	 ft_calctrim.c\
	 ft_intsize.c\
	 ft_fisblank.c\

OBJ = $(SRC:.c=.o)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I ./
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
