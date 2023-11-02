/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:12 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/02 10:01:54 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_cub *cub, char **copy)
{
	cub->s.spawncount = 0;
	cub->s.planex = 0;
	cub->s.planey = 0;
	cub->s.roof_color = string_to_rgb(cub, copy, 'C');
	cub->s.floor_color = string_to_rgb(cub, copy, 'F');
	set_textures(cub, copy);
	cub->s.map_h = hauteur_map(copy);
	cub->s.map_l = largeur_map(copy);
	cub->s.mapl = map_copy(cub, copy);
	free_chartab(copy);
	if (!is_map_closed(cub->s.mapl))
	{
		free_chartab(cub->s.mapl);
		exit(-1);
	}
	/*int i = 0;
	while (cub->s.mapl[i])
	{
		printf("%s\n", cub->s.mapl[i]);
		i++;
	}*/
	initcub(cub);
	get_text(cub);
	ft_refresh(cub);
}

void	init_pos(t_cub *cub, int h, int l)
{
	cub->s.posx = (h + 0.5);
	cub->s.posy = (l + 0.5);
}
