# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glebouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 11:44:49 by glebouch          #+#    #+#              #
#    Updated: 2018/03/19 11:25:44 by glebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#SRC = main.c get_next_line.c parallele.c parcing.c traitement_couleur.c parallele2.c isometrique.c
#SRC = main.c get_next_line.c argparallele.c parcing.c traitement_couleur.c isometrique.c
SRC = main.c color.c init.c mandelbrot.c

OBJ = $(SRC:.c=.o)

CC = clang

LIB = -L ./libft/ -lft -lmlx

INCLUDES = -I includes -I libft

FLAGS = -Wall -Wextra -Werror -O1

all : mlib $(NAME)

mlib :
	@make -C ./libft/


$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $^ $(LIB) -lX11 -lXext -O1

#$(NAME) : $(OBJ)
#	$(CC) $(LIB) $^ -o $@ -lX11 -lXext

%.o : %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean :
	@make -C ./libft/ clean
	@/bin/rm -f *.o
	
fclean : clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean	all
