/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:17:57 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:16:18 by lobertho         ###   ########.fr       */
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
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT 123
# define RIGHT 124
# define LARGEUR 1920
# define HAUTEUR 1080
# define MAPL 24
# define MAPH 24


enum {
		ON_DESTROY = 17
};

static int	g_worldmap[MAPL][MAPH]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_data {

	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		drawstart;
	int		drawend;
	int		w; //avancer
	int		s; //reculer
	int		a; //aller a gauche
	int		d; //aller a droite
	int		r; //tourner camera a gauche
	int		l; //tourner camera a droite
	int		lineHeight; // hauteur du mur
	int		hit; // si un mur est hit == 1 sinon 0
	int		hitside; // direction du mur touche
	int		mapX; //position du ray dans le square de la map en X
	int		mapY; //position du ray dans le square de la map en Y
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
	double	cameraX; //position de la camera sur l'ecran
	double	sideDistX; //distance du ray jusqu au prochain square en X
	double	sideDistY; //distnace du ray jusqu'au prochain square en Y
	double	deltaDistX; //distance du ray pour traverser un square d'un X a l'autre
	double	deltaDistY; //distance du ray pour traverser un square d'un Y a l'autre
	double	WallDist; //distnace entre le mur et la camera joueur
	double	h; // hauteur de la fenetre
	double	movespeed; //vitesse de deplacement
	double	rotspeed; //vitesse de rotation de la camera
}	t_data;

int	ft_kpress(int key, t_data *img);
int	ft_krelease(int key, t_data *s);
int	ft_exit(void);
int	ft_refresh(t_data *s);
int	ft_moove(t_data *s);
int	mooverl(t_data *s);
int	moovead(t_data *s);
int	moovews(t_data *s);

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	init_position(t_data *s);
void	cub(t_data *s);
void	initcub(t_data *s);
#endif