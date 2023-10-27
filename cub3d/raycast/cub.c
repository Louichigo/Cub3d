/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/27 18:32:27 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initcub(t_cub *cub)
{
	cub->s.h = HAUTEUR;
	cub->s.largeur = LARGEUR;
	cub->s.movespeed = 0.15;
	cub->s.rotspeed = 0.04;
	cub->s.a = 0;
	cub->s.d = 0;
	cub->s.w = 0;
	cub->s.s = 0;
	cub->s.l = 0;
	cub->s.r = 0;
}

int	ft_refresh(t_cub *cub)
{
	mlx_destroy_image(cub->s.mlx, cub->s.img);
	ft_moove(cub);
	cub->s.img = mlx_new_image(cub->s.mlx, LARGEUR, HAUTEUR);
	cub->s.addr = mlx_get_data_addr(cub->s.img, &cub->s.bits_per_pixel,
			&cub->s.line_length, &cub->s.endian);
	mlx_mouse_hide();
	cub3(cub);
	minimap(cub);
	mlx_put_image_to_window(cub->s.mlx, cub->s.mlx_win, cub->s.img, 0, 0);
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
}
