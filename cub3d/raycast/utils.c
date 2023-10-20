/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:39:41 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/20 12:14:50 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	exit(1);
}

void	my_mlx_pixel_put(t_cub *img, int x, int y, int color)
{
	char	*dest;

	dest = img->s.addr + (y * img->s.line_length + x
			* (img->s.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
