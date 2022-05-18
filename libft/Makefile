# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:20:11 by user              #+#    #+#              #
#    Updated: 2022/05/13 16:14:57 by pingpanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c \
	  ft_calloc.c \
	  ft_exist.c \
	  ft_isdigit.c \
	  ft_itoa.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnstr.c \
	  ft_uitoa_base.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "compile library libft.a"
	@ ar rc $(NAME) $^
	@ echo "done"

%.o : %.c 
	@ gcc -c $(FLAGS) $^ -I ./

.PHONY: all bonus clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus