/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:04:01 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_kpress(int key, t_data *s)
{
	if (key == ESC)
		ft_exit();
	else if (key == W)
		s->w = 1;
	else if	(key == S)
		s->s = 1;
	else if (key == A)
		s->a = 1;
	else if (key == D)
		s->d = 1;
	else if (key == RIGHT)
		s->r = 1;
	else if (key == LEFT)
		s->l = 1;
	return (0);
}

int	ft_krelease(int key, t_data *s)
{
	if (key == W)
		s->w = 0;
	else if	(key == S)
		s->s = 0;
	else if (key == A)
		s->a = 0;
	else if (key == D)
		s->d = 0;
	else if (key == RIGHT)
		s->r = 0;
	else if (key == LEFT)
		s->l = 0;
	return (0);
}




/*int	ft_hooks(int hook, t_data *img)
{
	return (0);
}*/