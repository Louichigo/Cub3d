/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:55:27 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/26 17:59:28 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycast(t_cub *cub)
{
	cub->s.camerax = 2 * cub->s.x / (double)cub->s.largeur -1;
	cub->s.raydirx = cub->s.dirx + cub->s.planex * cub->s.camerax;
	cub->s.raydiry = cub->s.diry + cub->s.planey * cub->s.camerax;
	cub->s.mapx = (int)cub->s.posx;
	cub->s.mapy = (int)cub->s.posy;
	cub->s.deltadistx = sqrt(1 + (cub->s.raydiry * cub->s.raydiry)
			/ (cub->s.raydirx * cub->s.raydirx));
	cub->s.deltadisty = sqrt(1 + (cub->s.raydirx * cub->s.raydirx)
			/ (cub->s.raydiry * cub->s.raydiry));
	cub->s.hit = 0;
}

void	init_directions(t_cub *cub)
{
	if (cub->s.raydirx < 0)
	{
		cub->s.stepx = -1;
		cub->s.sidedistx = (cub->s.posx - cub->s.mapx) * cub->s.deltadistx;
	}
	else
	{
		cub->s.stepx = 1;
		cub->s.sidedistx = (cub->s.mapx + 1.0 - cub->s.posx)
			* cub->s.deltadistx;
	}
	if (cub->s.raydiry < 0)
	{
		cub->s.stepy = -1;
		cub->s.sidedisty = (cub->s.posy - cub->s.mapy) * cub->s.deltadisty;
	}
	else
	{
		cub->s.stepy = 1;
		cub->s.sidedisty = (cub->s.mapy + 1.0 - cub->s.posy)
			* cub->s.deltadisty;
	}
}

void	dda_and_height(t_cub *cub)
{
	while (cub->s.hit == 0)
	{
		if (cub->s.sidedistx < cub->s.sidedisty)
		{
			cub->s.sidedistx += cub->s.deltadistx;
			cub->s.mapx += cub->s.stepx;
			cub->s.hitside = 0;
		}
		else
		{
			cub->s.sidedisty += cub->s.deltadisty;
			cub->s.mapy += cub->s.stepy;
			cub->s.hitside = 1;
		}
		if (cub->s.mapl[cub->s.mapx][cub->s.mapy] == '1')
			cub->s.hit = 1;
	}
	if (cub->s.hitside == 0)
		cub->s.walldist = fabs((cub->s.mapx - cub->s.posx
					+ (1 - cub->s.stepx) / 2) / cub->s.raydirx);
	else
		cub->s.walldist = fabs((cub->s.mapy - cub->s.posy
					+ (1 - cub->s.stepy) / 2) / cub->s.raydiry);
	cub->s.lineheight = (int)(cub->s.h / cub->s.walldist);
}

void	draw_walls(t_cub *cub)
{
	int	d;

	d = 0;
	cub->s.drawstart = -cub->s.lineheight / 2 + cub->s.h / 2;
	if (cub->s.drawstart < 0)
		cub->s.drawstart = 0;
	cub->s.drawend = cub->s.lineheight / 2 + cub->s.h / 2;
	if (cub->s.drawend >= cub->s.h)
		cub->s.drawend = cub->s.h;
	while (d < cub->s.drawstart)
		my_mlx_pixel_put(cub, cub->s.x, d++, cub->s.roof_color);
	d = cub->s.drawend;
	while (d > 0 && d < HAUTEUR)
		my_mlx_pixel_put(cub, cub->s.x, d++, cub->s.floor_color);
}
