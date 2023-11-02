# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:23:07 by lobertho          #+#    #+#              #
#    Updated: 2023/11/02 08:00:13 by cgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = $(wildcard *.c)	\
	   $(wildcard raycast/*.c) \
	   $(wildcard gnl/*.c)	\
	   $(wildcard parsing/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)

		make -C mlx
		$(CC) -I./mlx -Lmlx -lmlx $(FLAGS) $(MLX) -o $(NAME) $(OBJS)
	
clean:
		make clean -C mlx
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
