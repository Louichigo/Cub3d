/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:03:03 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/07 15:41:29 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*img;
	char	**copy;

	img = (t_cub *)malloc(sizeof(t_cub));
	if (!img)
		return (-1);
	copy = copy_fd(argc, argv);
	img->s.mlx = mlx_init();
	img->s.mlx_win = mlx_new_window(img->s.mlx, LARGEUR, HAUTEUR, "cub3d");
	img->s.img = mlx_new_image(img->s.mlx, LARGEUR, HAUTEUR);
	img->s.addr = mlx_get_data_addr(img->s.img, &img->s.bits_per_pixel,
			&img->s.line_length, &img->s.endian);
	img->s.addr2 = (int *)mlx_get_data_addr(img->s.img, &img->s.bits_per_pixel,
			&img->s.line_length, &img->s.endian);
	parsing(img, copy);
	mlx_hook(img->s.mlx_win, 2, (1L << 0), ft_kpress, img);
	mlx_hook(img->s.mlx_win, 3, (1L << 1), ft_krelease, img);
	mlx_hook(img->s.mlx_win, ON_DESTROY, 0, ft_exit, img);
	mlx_loop_hook(img->s.mlx, ft_refresh, img);
	mlx_loop(img->s.mlx);
}
