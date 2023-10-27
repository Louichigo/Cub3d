/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:33:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/27 19:04:49 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*mapchr(const char *s, int c)
{
	unsigned int	i;
	char			b;
	char			*str;

	i = 0;
	b = c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == b)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && b == '\0')
		return (str + i);
	else
		return (NULL);
}

void	drawmap(t_cub *cub, t_mapv start, int len, int color)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			my_mlx_pixel_put(cub, start.x + i, start.y + j, color);
			j++;
		}
		i++;
	}
}

void	minimap(t_cub *cub)
{
	t_mapv	start;
	int		x;
	int		y;

	start.x = 0;
	start.y = 0;
	/*y = cub->s.posy - RADIUS;
	if (y < 0)*/
		y = 0;
	while (y < MINIMAPSIZE && cub->s.mapl[y])
	{
		/*x = cub->s.posx - RADIUS;
		if (x < 0)*/
			x = 0;
		while (x < /*MINIMAPSIZE &&*/ cub->s.mapl[y][x])
		{
			start.x = (x /*- cub->s.posx + RADIUS*/) * MINIMAPSIZE;
			start.y = (y /*- cub->s.posy + RADIUS*/) * MINIMAPSIZE;
			if (mapchr("1 ", cub->s.mapl[y][x]))
				drawmap(cub, start, MINIMAPSIZE, 0x00000000);
			if (mapchr("0", cub->s.mapl[y][x]))
				drawmap(cub, start, MINIMAPSIZE, 0x00EEEEE4);
			x++;
		}
		y++;
	}
}