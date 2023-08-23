/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:39:41 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/13 18:42:37 by lobertho         ###   ########.fr       */
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

	dest = img->addr + (y * img->line_length + x
					* (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}