/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/17 15:24:06 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initcub(t_cub *cub)
{
	cub->s.h = HAUTEUR;
	cub->s.largeur = LARGEUR;
	cub->s.color = 0x00FF0000;
	cub->s.posx = 22;
	cub->s.posy = 12;
	cub->s.dirx = -1;
	cub->s.diry = 0;
	cub->s.planex = 0;
	cub->s.planey = 0.66;
	cub->s.movespeed = 0.09;
	cub->s.rotspeed = 0.03;
	cub->s.a = 0;
	cub->s.d = 0;
	cub->s.w = 0;
	cub->s.s = 0;
	cub->s.l = 0;
	cub->s.r = 0;
	cub->s.no_wall = "./textures/NO.xpm";
	cub->s.so_wall = "./textures/SO.xpm";
	cub->s.we_wall = "./textures/WE.xpm";
	cub->s.ea_wall = "./textures/EA.xpm";
}

int	ft_refresh(t_cub *cub)
{
	mlx_destroy_image(cub->s.mlx, cub->s.img);
	ft_moove(cub);
	cub->s.img = mlx_new_image(cub->s.mlx, LARGEUR, HAUTEUR);
	cub->s.addr = mlx_get_data_addr(cub->s.img, &cub->s.bits_per_pixel,
			&cub->s.line_length, &cub->s.endian);
	cub3(cub);
	return (0);
}

void	cub3(t_cub *cub)
{
	cub->s.x = 0;
	while (cub->s.x < LARGEUR)
	{
		init_raycast(cub);
		init_directions(cub);
		dda_and_height(cub);
		draw_walls(cub);
		textures(cub, cub->s.x);
		cub->s.x++;
	}
	mlx_put_image_to_window(cub->s.mlx, cub->s.mlx_win, cub->s.img, 0, 0);
}
