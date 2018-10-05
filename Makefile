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

SRC = main.c tools.c julia.c mandelbrot.c burningships.c hook.c

OBJ = $(SRC:.c=.o)

CC = gcc

LIB = -L ./libft/ -lft -lm -L ./minilibX/ -lmlx

INCLUDES = -I fractol.h -I libft/libft.h

CFLAGS = -Wall -Wextra -Werror -O1 -g

#pour mac
FLAGS = -framework OpenGL -framework AppKit
#pour pc :
#FLAGS= -lX11 -lXext -O1 -g

all : mlib $(NAME)

mlib :
	@make -C ./libft/


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $(LIB) $^ -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

clean :
	@make -C ./libft/ clean
	@/bin/rm -f *.o
	
fclean : clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean	all
