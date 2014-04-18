# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/16 16:01:48 by abrault           #+#    #+#              #
#    Updated: 2014/04/17 17:01:43 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/main.c \
	  src/get_command.c \
	  src/list.c \
	  src/sort.c \
	  src/display.c

LIB = libft/libft.a

LIB_INC = libft/includes/

LIB_DIR = libft

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

$(LIB):
	cd $(LIB_DIR) && $(MAKE)

%.o: %.c
	gcc -c $(CFLAGS) -I./includes/ $< -o $@ -I . -I $(LIB_INC)

clean:
	cd $(LIB_DIR) && $(MAKE) clean
	rm -rf $(OBJ)


fclean: clean
	cd $(LIB_DIR) && $(MAKE) fclean
	rm -rf $(NAME)

re: fclean all
