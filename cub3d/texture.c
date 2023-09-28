/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:33:17 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/28 16:10:05 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_texture(t_data *s)
{
	if (s->hitside == 0 && s->raydirX >= 0)
		s->texnb = 0;
	else if (s->hitside == 0 && s->raydirX < 0)
		s->texnb = 1;
	else if (s->hitside == 1 && s->raydirY >= 0)
		s->texnb = 2;
	else if (s->hitside == 1 && s->raydirY < 0)
		s->texnb = 3;
	else
		s->texnb = 0;
}

void	init_textures(t_data *s)
{
	s->texNum = g_worldmap[s->mapX][s->mapY] - 1;
	if (s->hitside == 0)
		s->wallX = s->posY + s->WallDist * s->raydirX;
	else
		s->wallX = s->posX + s->WallDist * s->raydirX;
	s->texX = (int)(s->wallX * (double)texWidth);
	if (s->hitside == 0 && s->raydirX > 0)
		s->texX = texWidth - s->texX - 1;
	if (s->hitside == 1 && s->raydirY < 0)
		s->texX = texWidth - s->texX - 1;
	s->step = 1.0 * texHeight / s->lineHeight;
	s->texpos = (s->drawstart - s->h / 2 + s->lineHeight / 2) * s->step;	
}

void	textures(t_data *s, int x)
{
	int	y;

	find_texture(s);
	init_textures(s);
	while (++y <= s->drawend)
	{
		s->texY = (int)s->texpos & (texHeight - 1);
		s->texpos += s->step;
		if (y < HAUTEUR && x < LARGEUR)
		{
				
		}
	}
}