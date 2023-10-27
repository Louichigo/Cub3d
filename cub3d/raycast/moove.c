/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:52:50 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/26 18:00:50 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_moove(t_cub *cub)
{
	if (cub->s.w == 1 || cub->s.s == 1)
		moovews(cub);
	if (cub->s.a == 1 || cub->s.d == 1)
		moovead(cub);
	if (cub->s.r == 1)
		turnright(cub);
	if (cub->s.l == 1)
		turnleft(cub);
	return (0);
}

int	moovews(t_cub *cub)
{
	if (cub->s.w == 1)
	{
		if (cub->s.mapl[(int)(cub->s.posx + cub->s.dirx
				* cub->s.movespeed)][(int)(cub->s.posy)] == '0')
			cub->s.posx += cub->s.dirx * cub->s.movespeed;
		if (cub->s.mapl[(int)(cub->s.posx)][(int)(cub->s.posy + cub->s.diry
				* cub->s.movespeed)] == '0')
			cub->s.posy += cub->s.diry * cub->s.movespeed;
	}
	if (cub->s.s == 1)
	{
		if (cub->s.mapl[(int)(cub->s.posx - cub->s.dirx
				* cub->s.movespeed)][(int)(cub->s.posy)] == '0')
			cub->s.posx -= cub->s.dirx * cub->s.movespeed;
		if (cub->s.mapl[(int)(cub->s.posx)][(int)(cub->s.posy - cub->s.diry
				* cub->s.movespeed)] == '0')
			cub->s.posy -= cub->s.diry * cub->s.movespeed;
	}
	return (0);
}

int	moovead(t_cub *cub)
{
	if (cub->s.d == 1)
	{
		if (cub->s.mapl[(int)(cub->s.posx + cub->s.planex
				* cub->s.movespeed)][(int)(cub->s.posy)] == '0')
			cub->s.posx += cub->s.planex * cub->s.movespeed;
		if (cub->s.mapl[(int)(cub->s.posx)][(int)(cub->s.posy + cub->s.planey
				* cub->s.movespeed)] == '0')
			cub->s.posy += cub->s.planey * cub->s.movespeed;
	}
	if (cub->s.a == 1)
	{
		if (cub->s.mapl[(int)(cub->s.posx - cub->s.planex
				* cub->s.movespeed)][(int)(cub->s.posy)] == '0')
			cub->s.posx -= cub->s.planex * cub->s.movespeed;
		if (cub->s.mapl[(int)(cub->s.posx)][(int)(cub->s.posy - cub->s.planey
				* cub->s.movespeed)] == '0')
			cub->s.posy -= cub->s.planey * cub->s.movespeed;
	}
	return (0);
}

int	turnright(t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	if (cub->s.r == 1)
	{
		olddirx = cub->s.dirx;
		cub->s.dirx = cub->s.dirx * cos(-cub->s.rotspeed) - cub->s.diry
			* sin(-cub->s.rotspeed);
		cub->s.diry = olddirx * sin(-cub->s.rotspeed) + cub->s.diry
			* cos(-cub->s.rotspeed);
		oldplanex = cub->s.planex;
		cub->s.planex = cub->s.planex * cos(-cub->s.rotspeed) - cub->s.planey
			* sin(-cub->s.rotspeed);
		cub->s.planey = oldplanex * sin(-cub->s.rotspeed) + cub->s.planey
			* cos(-cub->s.rotspeed);
	}
	return (0);
}

int	turnleft(t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	if (cub->s.l == 1)
	{
		olddirx = cub->s.dirx;
		cub->s.dirx = cub->s.dirx * cos(cub->s.rotspeed) - cub->s.diry
			* sin(cub->s.rotspeed);
		cub->s.diry = olddirx * sin(cub->s.rotspeed) + cub->s.diry
			* cos(cub->s.rotspeed);
		oldplanex = cub->s.planex;
		cub->s.planex = cub->s.planex * cos(cub->s.rotspeed) - cub->s.planey
			* sin(cub->s.rotspeed);
		cub->s.planey = oldplanex * sin(cub->s.rotspeed) + cub->s.planey
			* cos(cub->s.rotspeed);
	}
	return (0);
}
