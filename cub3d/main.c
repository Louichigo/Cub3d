/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:03:03 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/14 18:28:41 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data *img;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (-1);
	(void)argc;
	(void)argv;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, LARGEUR, HAUTEUR, "cub3d");
	img->img = mlx_new_image(img->mlx, LARGEUR, HAUTEUR);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
	//parsing(img);
	cub(img);
	mlx_key_hook(img->mlx_win, ft_keys, img);
	//mlx_mouse_hook(img->mlx_win, ft_hooks, img);
	mlx_hook(img->mlx_win, ON_DESTROY, 0, ft_exit, img);
	mlx_loop(img->mlx);
}