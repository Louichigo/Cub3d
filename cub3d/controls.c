/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/13 18:38:24 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_keys(int key, t_data *img)
{
	(void)img;
	if (key == ESC)
		ft_exit();
	return (0);
}

/*int	ft_hooks(int hook, t_data *img)
{
	return (0);
}*/