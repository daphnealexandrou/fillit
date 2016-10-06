# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 10:24:38 by dalexand          #+#    #+#              #
#    Updated: 2016/04/28 14:29:50 by adenece          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Wextra

INCLUDES = -I ./libft

HEADERS = libft/libft.h fillit.h

SRC = map.c main.c math.c parsing.c solve.c read.c 

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(SRC) $(INCLUDES) -L./libft -lft

libft/libft.a: $(OBJ_LIBFT)
	ar rc libft/libft.a $(OBJ_LIBFT)
	
%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_LIBFT) libft/libft.a

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean clean all
