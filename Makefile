# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:53:17 by user              #+#    #+#              #
#    Updated: 2022/05/13 15:58:46 by pingpanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#defind names
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

#color
DEFCOLOR = '\033[0m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
WHITE = '\033[0;37'
BLUE = '\033[0;34'

#source files locales
SRC = srcs/ft_printf.c \
	  srcs/get_params.c \
	  srcs/ft_putspecs.c \
	  srcs/ft_dowidth.c \
	  srcs/print_c.c \
	  srcs/print_id.c \
	  srcs/print_p.c \
	  srcs/print_s.c \
	  srcs/print_u.c \
	  srcs/print_x.c \
	  srcs/print_utils.c\
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = ./incs

#operations
#1. Run makefile in libft to get libft.a
#2. mkdir build
#3. compile .c files in srcs to .o and put them to build
#4. compile all files in build
OBJS = $(.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		 @make -C $(LIBFT)
		 @

$(OBJS) :$(BUILD_DIR)/%.o:$%.c
		 @mkdir -p $(@D)
		 @echo "Compiling $<"
		 @$(CC) $(FLAGS) -I $(INC) -I $(SRC) -c $< -o $@

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
	@echo "$(GREEN)=== Credit TSOMSA (viruskizz github) Thanks ===$(DEF_GREEN)"
	@echo "$(BLUE)=== KHAONIAO ===$(DEF_BLUE)"
	@./khaoniao.out-I $(INC)

testmem: re
	@$(CC) main.c -lftprintf -L . -I $(INC) -o khaoniao.out
	@echo "\033[0;032=== KHAONIAO ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./khaoniao.out

.PHONY: all clean fclean re
