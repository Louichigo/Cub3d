# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:23:07 by lobertho          #+#    #+#              #
#    Updated: 2023/07/13 18:43:50 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = main.c controls.c utils.c cub.c

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -I./mlx -Lmlx -lmlx $(FLAGS) -o $(NAME) $(OBJS)
	
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all