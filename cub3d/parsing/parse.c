/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:12 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/27 11:12:54 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_cub *cub, char **copy)
{
	cub->s.spawncount = 0;
	cub->s.planex = 0;
	cub->s.planey = 0;
	cub->s.roof_color = string_to_rgb(copy, 'C');
	cub->s.floor_color = string_to_rgb(copy, 'F');
	cub->s.no_wall = textures_path(copy, "NO");
	cub->s.so_wall = textures_path(copy, "SO");
	cub->s.we_wall = textures_path(copy, "WE");
	cub->s.ea_wall = textures_path(copy, "EA");
	cub->s.map_h = hauteur_map(copy);
	cub->s.map_l = largeur_map(copy);
	cub->s.mapl = map_copy(cub, copy);
	free_chartab(copy);
	/*int i = 0;
	while (cub->s.mapl[i])
	{
		printf("%s\n", cub->s.mapl[i]);
		i++;
	}*/
	initcub(cub);
	get_text(cub);
	cub3(cub);
}

void	init_pos(t_cub *cub, int h, int l)
{
	cub->s.posx = (h + 0.5);
	cub->s.posy = (l + 0.5);
}
