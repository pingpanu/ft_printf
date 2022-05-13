# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:53:17 by user              #+#    #+#              #
#    Updated: 2022/05/12 22:14:53 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = ./incs

BUILD_DIR = build
SRC = ft_printf.c \
	  get_params.c \
	  ft_putspecs.c \
	  ft_dowidth.c \
	  utils/print_c.c \
	  utils/print_id.c \
	  utils/print_p.c \
	  utils/print_s.c \
	  utils/print_u.c \
	  utils/print_x.c \
	  utils/print_utils.c\

OBJS = $(.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		 @echo "Composing $@"
		 @ar rc $(NAME) $(OBJS)
		 @echo "Done!"

$(OBJS) :$(BUILD_DIR)/%.o:$%.c
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

test: re
	@$(CC) -o khaoniao.out main.c -L . libftprintf.a -I $(INC) 
	@echo "\033[0;31m=== Credit TSOMSA (viruskizz github) Thanks ===\033[0m"
	@echo "\033[0;32m=== KHAONIAO ===\033[0m"
	@./khaoniao.out-I $(INC)

testmem: re
	@$(CC) main.c -lftprintf -L . -I $(INC) -o khaoniao.out
	@echo "\033[0;032=== KHAONIAO ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./khaoniao.out

.PHONY: all clean fclean re