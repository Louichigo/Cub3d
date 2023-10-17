# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:23:07 by lobertho          #+#    #+#              #
#    Updated: 2023/10/11 16:54:48 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = main.c controls.c utils.c cub.c moove.c raycast.c texture.c

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