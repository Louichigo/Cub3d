/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:52:50 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/26 12:04:45 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_moove(t_data *s)
{
	if (s->w == 1 || s->s == 1)
		moovews(s);
	if (s->a == 1 || s->d == 1)
		moovead(s);
	if (s->r == 1 || s->l == 1)
		mooverl(s);
	return (0);
}

int	moovews(t_data *s)
{
	if (s->w == 1)
	{
		if (g_worldmap[(int)(s->posX + s->dirX * s->movespeed)][(int)(s->posY)] == 0)
			s->posX += s->dirX * s->movespeed;
		if (g_worldmap[(int)(s->posX)][(int)(s->posY + s->dirY * s->movespeed)] == 0)
			s->posY += s->dirY * s->movespeed;
	}
	if (s->s == 1)
	{
		if (g_worldmap[(int)(s->posX - s->dirX * s->movespeed)][(int)(s->posY)] == 0)
			s->posX -= s->dirX * s->movespeed;
		if (g_worldmap[(int)(s->posX)][(int)(s->posY - s->dirY * s->movespeed)] == 0)
			s->posY -= s->dirY * s->movespeed;	
	}
	return (0);
}

int	moovead(t_data *s)
{
	if (s->d == 1)
	{
		if (g_worldmap[(int)(s->posX + s->planeX * s->movespeed)][(int)(s->posY)] == 0)
			s->posX += s->planeX * s->movespeed;
		if (g_worldmap[(int)(s->posX)][(int)(s->posY + s->planeY * s->movespeed)] == 0)
			s->posY += s->planeY * s->movespeed;
	}
	if (s->a == 1)
	{
		if (g_worldmap[(int)(s->posX - s->planeX * s->movespeed)][(int)(s->posY)] == 0)
			s->posX -= s->planeX * s->movespeed;
		if (g_worldmap[(int)(s->posX)][(int)(s->posY - s->planeY * s->movespeed)] == 0)
			s->posY -= s->planeY * s->movespeed;	
	}
	return (0);
}

int	mooverl(t_data *s)
{
	if (s->r == 1)
	{
		double oldDirX = s->dirX;
		s->dirX = s->dirX * cos(-s->rotspeed) - s->dirY * sin(-s->rotspeed);
		s->dirY = oldDirX * sin(-s->rotspeed) + s->dirY * cos(-s->rotspeed);
		double oldPlaneX = s->planeX;
		s->planeX = s->planeX * cos(-s->rotspeed) - s->planeY * sin(-s->rotspeed);
		s->planeY = oldPlaneX * sin(-s->rotspeed) + s->planeY * cos(-s->rotspeed);
	}
	if (s->l == 1)
	{
		double oldDirX = s->dirX;
		s->dirX = s->dirX * cos(s->rotspeed) - s->dirY * sin(s->rotspeed);
		s->dirY = oldDirX * sin(s->rotspeed) + s->dirY * cos(s->rotspeed);
		double oldPlaneX = s->planeX;
		s->planeX = s->planeX * cos(s->rotspeed) - s->planeY * sin(s->rotspeed);
		s->planeY = oldPlaneX * sin(s->rotspeed) + s->planeY * cos(s->rotspeed);
	}
	return (0);
}