/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:08:08 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_position(t_data *s)
{
	int	x = 0;
	int	w = LARGEUR;
	while (x < w)
	{
		//init raycast
		s->cameraX = 2 * x / (double)w -1;
		s->raydirX = s->dirX + s->planeX * s->cameraX;
		s->raydirY = s->dirY + s->planeY * s->cameraX;
		s->mapX = (int)s->posX;
		s->mapY = (int)s->posY;
		s->deltaDistX = sqrt(1 + (s->raydirY * s->raydirY) / (s->raydirX * s->raydirX));
      	s->deltaDistY = sqrt(1 + (s->raydirX * s->raydirX) / (s->raydirY * s->raydirY));
		s->hit = 0;


		//Calcul du step et du sidedist
		if (s->raydirX < 0)
		{
			s->stepX = -1;
			s->sideDistX = (s->posX - s->mapX) * s->deltaDistX;
		}
		else
		{
			s->stepX = 1;
			s->sideDistX = (s->mapX + 1.0 - s->posX) * s->deltaDistX;
		}
		if (s->raydirY < 0)
		{
			s->stepY = -1;
			s->sideDistY = (s->posY - s->mapY) * s->deltaDistY;
		}
		else
		{
			s->stepY = 1;
			s->sideDistY = (s->mapY + 1.0 - s->posY) * s->deltaDistY;
		}


		//DDA (digital differential analysis): calcul du hit des ray en boucle
		while (s->hit == 0)
		{
			//aller au prochain carrer en x ou y
			if (s->sideDistX < s->sideDistY)
			{
				s->sideDistX += s->deltaDistX;
				s->mapX += s->stepX;
				s->hitside = 0;
			}
			else
			{
				s->sideDistY += s->deltaDistY;
				s->mapY += s->stepY;
				s->hitside = 1;
			}
			//check si un ray a toucher un mur
			if (g_worldmap[s->mapX][s->mapY] > 0)
				s->hit = 1;
		}


		//calculer la sitance ray - mur pour connaitre la hauteur a dessiner du mur via la camera
		if (s->hitside == 0)
			s->WallDist = fabs((s->mapX - s->posX + (1 - s->stepX) / 2) / s->raydirX);
		else
			s->WallDist = fabs((s->mapY - s->posY + (1 - s->stepY) / 2) / s->raydirY);

		//calcule de la hauteur a dessiner
		s->lineHeight = (int)(s->h / s->WallDist);


		//calcule le plus bas et le plus haut pixel des murs
		s->drawstart = -s->lineHeight / 2 + s->h / 2;
		if (s->drawstart < 0)
			s->drawstart = 0;
		s->drawend = s->lineHeight / 2 + s->h / 2;
		if (s->drawend >= s->h)
			s->drawend = s->h;

		//dessiner le plafond
		int	d = 0;
		while (d < s->drawstart)
			my_mlx_pixel_put(s, x, d++, 0x00000080);


		//dessiner les murs
		while (s->drawstart < s->drawend)
			my_mlx_pixel_put(s, x, s->drawstart++, s->color);


		//dessiner le sol
		d = s->drawend;
		while (d > 0 && d < HAUTEUR)
			my_mlx_pixel_put(s, x, d++, 0x0000FF00);
		x++;
	}
	
}
void	initcub(t_data *s)
{
	s->h = HAUTEUR;
	s->color = 0x00FF0000;
	s->posX = 22;
	s->posY = 12;
	s->dirX = -1;
	s->dirY = 0;
	s->planeX = 0;
	s->planeY = 0.66;
	s->movespeed = 0.1;
	s->rotspeed = 0.03;
	s->a = 0;
	s->d = 0;
	s->w = 0;
	s->s = 0;
	s->l = 0;
	s->r = 0;
}

int	ft_refresh(t_data *s)
{
	ft_moove(s);
	cub(s);
	return (0);
}


void	cub(t_data *s)
{
	init_position(s);
	mlx_put_image_to_window(s->mlx, s->mlx_win,	s->img, 0, 0);
}