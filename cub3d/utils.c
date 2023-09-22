/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:39:41 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/24 14:56:07 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(void)
{
	exit(1);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dest;

	/*if (x < 0 || y < 0 || x > LARGEUR || y > HAUTEUR)
		return ;*/
	dest = img->addr + (y * img->line_length + x
					* (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}