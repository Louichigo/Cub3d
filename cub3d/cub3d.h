/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:17:57 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/14 18:56:50 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/mlx.h"

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define LARGEUR 640
# define HAUTEUR 480

enum {
		ON_DESTROY = 17
};

typedef struct s_data {

	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		drawstart;
	int		drawend;
	int		lineHeight; // hauteur du mur
	int		hit;
	int		hitside; // direction du mur touche
	int		stepX; //direction ou aller en X
	int		stepY; //direction ou aller en Y
	double	posX; //position du joueur en X
	double	posY; //position du joueur en Y
	double	dirX; //direction du joueur en X
	double	dirY; //direction du joueur en Y
	double	planeX; //camera du joueur en X perpendiculaire a la direction
	double	planeY; //camera du joueur en Y perpendiculaire a la direction
	double	raydirX; //direction du ray en X
	double	raydirY; //direction du ray en Y
	double	cameraX; //position de la camera sur l'ecran en X
	double	cameraY; //position de la camere sur l'ecran en Y
	double	sideDistX; //distance du ray jusqu au prochain square en X
	double	sideDistY; //distnace du ray jusqu'au prochain square en Y
	double	deltaDistX; //distance du ray pour traverser un square d'un X a l'autre
	double	deltaDistY; //distance du ray pour traverser un square d'un Y a l'autre
	double	WallDist; //distnace entre le mur et la camera joueur
	double	h;
}	t_data;

int	ft_keys(int key, t_data *img);
int	ft_hooks(int hook, t_data *img);
int	ft_exit(void);

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	init_position(t_data *s);
void	cub(t_data *s);

#endif