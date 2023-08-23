/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/14 18:59:58 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_position(t_data *s)
{
	int	worldmap[5][5]=
	{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,1,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
	};

	int	x = 0;
	int	w;
	while (x < w)
	{
		s->cameraX = 2 * x / (double)w -1;
		s->raydirX = s->dirX + s->planeX * s->cameraX;
		s->raydirY = s->dirY + s->planeY * s->cameraY;
		int	mapX = (int)s->posX;
		int	mapY = (int)s->posY;
		s->sideDistX = abs(1 / s->raydirX);
		s->sideDistY = abs(1 / s->raydirY);
		s->hit = 0;
		//Calcul du step et du sidedist
		if (s->raydirX < 0)
		{
			s->stepX = -1;
			s->sideDistX = (s->posX - mapX) * s->deltaDistX;
		}
		else
		{
			s->stepX = 1;
			s->sideDistX = (mapX + 1.0 - s->posX) * s->deltaDistX;
		}
		if (s->raydirY < 0)
		{
			s->stepY = -1;
			s->sideDistY = (s->posY - mapY) * s->deltaDistY;
		}
		else
		{
			s->stepY = 1;
			s->sideDistY = (mapY + 1.0 - s->posY) * s->deltaDistY;
		}
		//DDA (digital differential analysis): calcul du hit des ray en boucle
		while (s->hit == 0)
		{
			//aller au prochain carrer en x ou y
			if (s->sideDistX < s->sideDistY)
			{
				s->sideDistX += s->deltaDistX;
				mapX += s->stepX;
				s->hitside = 0;
			}
			else
			{
				s->sideDistY += s->deltaDistY;
				mapY = s->stepY;
				s->hitside = 1;
			}
			//check si un ray a toucher un mur
			if (worldmap[mapX][mapY] > 0)
				s->hit == 1;
		}
		//calculer la sitance ray - mur pour connaitre la hauteur a dessiner du mur via la camera
		if (s->hitside == 0)
			s->WallDist = (s->sideDistX - s->deltaDistX);
		else
			s->WallDist = (s->sideDistY - s->deltaDistY);
		//calcule de la hauteur a dessiner
		s->lineHeight = (int)(s->h / s->WallDist);
		//calcule le plus bas et le plus haut pixel
		s->drawstart = s->lineHeight / 2 + s->h / 2;
		if (s->drawstart < 0)
			s->drawstart = 0;
		s->drawend = s->lineHeight / 2 + s->h / 2;
		if (s->drawend >= s->h)
			s->drawend = s->h - 1;
		x++;
	}
	
}

void	cub(t_data *s)
{
	int	x = 0;
	int	y = 0;
	s->posX = 3;
	s->posY = 2;
	s->dirX = -1;
	s->dirY = 0;
	s->planeX = 0;
	s->planeY = 0.66;
	while (x < LARGEUR)
	{
		while (y < HAUTEUR)
		{
			init_position(s);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->mlx_win,	s->img, 0, 0);
}