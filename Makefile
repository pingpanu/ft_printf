# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:53:17 by user              #+#    #+#              #
#    Updated: 2022/05/28 00:08:26 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
BDIR = build/
SDIR = srcs/
LIB = libft
INC = incs

#color
DEFCOLOR = '\033[0m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
WHITE = '\033[0;37m'

#sources
SRC_NAME = ft_printf.c \
	  	   get_params.c \
	  	   ft_putall.c \
		   utils/ft_dowidth.c \
		   utils/ft_doflag.c \
		   utils/idux_prec.c \
		   utils/print_utils.c \
	  	   print_c.c \
	  	   print_id.c \
	  	   print_p.c \
	  	   print_s.c \
	  	   print_u.c \
	  	   print_x.c

SRCS = $(addprefix $(SDIR), $(SRC_NAME))
OBJS = $(addprefix $(BDIR), $(SRC_NAME:.c=.o))
OBJF = .cache_exist

#operations
#1. Run makefile in libft to get libft.a
#2. mkdir build
#3. compile .c files in srcs to .o and put them to build
#4. compile all files in build

all: $(NAME)

$(NAME): $(OBJS)
		 @ make -C $(LIB)
		 @ cp $(LIB)/libft.a $(NAME)
		 @ echo "$(YELLOW)Compile srcs files to libftprintf$(DEFCOLOR)"
		 @ ar rcs $(NAME) $(OBJS)
		 @ echo "$(GREEN)Done!$(DEFCOLOR)"

$(BDIR)%.o: $(SDIR)%.c | $(OBJF)
		 @ echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
		 @ $(CC) $(FLAGS) -c $< -o $@ -I $(INC) -I $(LIB)

$(OBJF):
		 @ mkdir -p $(BDIR)
		 @ mkdir -p $(BDIR)/utils

bonus: all

clean:
		 @ rm -rf $(BDIR)
		 @ make clean -C $(LIB)
		 @ echo "$(BLUE)Object files removed$(DEFCOLOR)"

fclean: clean
		 @ rm -f $(NAME)
		 @ make fclean -C $(LIB)
		 @ echo "$(BLUE)All libraries removed$(DEFCOLOR)"

re: fclean all
		 @ echo "$(GREEN)Ft_printf succesfully rebuilded$(DEFCOLOR)"

rebonus: fclean bonus

norm:
		 @ norminette $(SRCS) $(INC) $(LIB) | grep -v Norme -B1 || true

test: re
	@$(CC) $(FLAGS) -o khaoniao.out main.c -L . -lftprintf -I incs/
	@echo "$(GREEN)=== Credit TSOMSA (viruskizz github) Thanks ===$(DEFCOLOR)"
	@echo "$(BLUE)=== KHAONIAO ===$(DEFCOLOR)"

testmem: re
	@$(CC) $(FLAGS) -o khaoniao.out main.c -L . -lftprintf -I incs/
	@echo "$(BLUE)=== KHAONIAO ===$(DEFCOLOR)"
	@valgrind -q --leak-check=full --track-origins=yes ./khaoniao.out

.PHONY: all clean fclean re