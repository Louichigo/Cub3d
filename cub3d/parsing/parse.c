/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:12 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/23 22:38:16 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_cub *cub, char **copy)
{
	char	**mapl;

	cub->s.roof_color = string_to_rgb(copy, 'C');
	cub->s.floor_color = string_to_rgb(copy, 'F');
	cub->s.no_wall = textures_path(copy, "NO");
	cub->s.so_wall = textures_path(copy, "SO");
	cub->s.we_wall = textures_path(copy, "WE");
	cub->s.ea_wall = textures_path(copy, "EA");
	cub->s.map_h = hauteur_map(copy);
	cub->s.map_l = largeur_map(copy);
	mapl = map_copy(copy);
	cub->s.map = map_init(cub, mapl);
	initcub(cub);
	get_text(cub);
	cub3(cub);
//	free_chartab(copy);
	//free_chartab(mapl);
}
