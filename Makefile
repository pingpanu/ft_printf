# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:53:17 by user              #+#    #+#              #
#    Updated: 2022/04/19 09:58:55 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

INC = ft_printf.h
LIBFT_DIR = ./libft
BUILD_DIR = build

SRC = ft_printf.c \
	  get_params.c \
	  ft_putall.c \
	  ft_putspecs.c \
	  ft_print_cases.c \
	  ft_printflag.c \
	  ft_printwidth.c \
	  ft_dowidth.c \

OBJS = $(%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		 @echo "Compiling $@"
		 @ar rc $(NAME) $(OBJS)
		 @echo "Done!"

$(OBJS) :(BUILD_DIR)/%.o:%.c
		 @mkdir -p $(@D)
		 @echo "Compiling $<"
		 @$(CC) $(FLAGS) -I $(INC) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT) :
		 make -C $(LIBFT_DIR)
		 cp $(LIBFT) $(NAME)

bonus: all

clean:
	   make clean -C $(LIBFT_DIR)
	   $(RM) -r $(BUILD_DIR)

fclean: clean
	   make fclean -C $(LIBFT_DIR)
	   $(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re