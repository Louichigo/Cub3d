/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/25 13:20:12 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_kpress(int key, t_cub *cub)
{
	if (key == ESC)
		ft_exit(cub);
	else if (key == W)
		cub->s.w = 1;
	else if (key == S)
		cub->s.s = 1;
	else if (key == A)
		cub->s.a = 1;
	else if (key == D)
		cub->s.d = 1;
	else if (key == RIGHT)
		cub->s.r = 1;
	else if (key == LEFT)
		cub->s.l = 1;
	return (0);
}

int	ft_krelease(int key, t_cub *cub)
{
	if (key == W)
		cub->s.w = 0;
	else if (key == S)
		cub->s.s = 0;
	else if (key == A)
		cub->s.a = 0;
	else if (key == D)
		cub->s.d = 0;
	else if (key == RIGHT)
		cub->s.r = 0;
	else if (key == LEFT)
		cub->s.l = 0;
	return (0);
}
