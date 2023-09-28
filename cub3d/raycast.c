/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:55:27 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/28 15:19:21 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_data *s)
{
	s->cameraX = 2 * s->x / (double)s->largeur -1;
	s->raydirX = s->dirX + s->planeX * s->cameraX;
	s->raydirY = s->dirY + s->planeY * s->cameraX;
	s->mapX = (int)s->posX;
	s->mapY = (int)s->posY;
	s->deltaDistX = sqrt(1 + (s->raydirY * s->raydirY) / (s->raydirX * s->raydirX));
    s->deltaDistY = sqrt(1 + (s->raydirX * s->raydirX) / (s->raydirY * s->raydirY));
	s->hit = 0;
}

void	init_directions(t_data *s)
{
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
}

void	dda_and_height(t_data *s)
{
	while (s->hit == 0)
	{
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
		if (g_worldmap[s->mapX][s->mapY] > 0)
			s->hit = 1;
	}
	if (s->hitside == 0)
		s->WallDist = fabs((s->mapX - s->posX + (1 - s->stepX) / 2) / s->raydirX);
	else
		s->WallDist = fabs((s->mapY - s->posY + (1 - s->stepY) / 2) / s->raydirY);
	s->lineHeight = (int)(s->h / s->WallDist);
}

void	draw_walls(t_data *s)
{
	int	d;

	d = 0;
	s->drawstart = -s->lineHeight / 2 + s->h / 2;
	if (s->drawstart < 0)
		s->drawstart = 0;
	s->drawend = s->lineHeight / 2 + s->h / 2;
	if (s->drawend >= s->h)
		s->drawend = s->h;
	while (d < s->drawstart)
		my_mlx_pixel_put(s, s->x, d++, 0x000000FF);
	while (s->drawstart < s->drawend)
		my_mlx_pixel_put(s, s->x, s->drawstart++, s->color);
	d = s->drawend;
	while (d > 0 && d < HAUTEUR)
		my_mlx_pixel_put(s, s->x, d++, 0x0000FF00);
}