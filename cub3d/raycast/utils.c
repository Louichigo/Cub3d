/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:39:41 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/02 10:21:07 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(t_cub *cub)
{
	(void)cub;
	free_chartab(cub->s.mapl);
	free_tex(cub);
	exit(1);
}

int	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	my_mlx_pixel_put(t_cub *img, int x, int y, int color)
{
	char	*dest;

	dest = img->s.addr + (y * img->s.line_length + x
			* (img->s.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
