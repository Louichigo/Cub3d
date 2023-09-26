/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/26 12:07:36 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initcub(t_data *s)
{
	s->h = HAUTEUR;
	s->largeur = LARGEUR;
	s->color = 0x00FF0000;
	s->posX = 22;
	s->posY = 12;
	s->dirX = -1;
	s->dirY = 0;
	s->planeX = 0;
	s->planeY = 0.66;
	s->movespeed = 0.09;
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
	s->x = 0;
	while (s->x < LARGEUR)
	{
		init_raycast(s);
		init_directions(s);
		dda_and_height(s);
		draw_walls(s);
		s->x++;
	}
	mlx_put_image_to_window(s->mlx, s->mlx_win,	s->img, 0, 0);
}