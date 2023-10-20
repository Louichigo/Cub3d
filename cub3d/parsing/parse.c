/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:12 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/20 16:08:23 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_cub *cub, char **copy)
{
	cub->s.roof_color = string_to_rgb(copy, 'C');
	cub->s.floor_color = string_to_rgb(copy, 'F');
	cub->s.no_wall = textures_path(copy, "NO");
	cub->s.so_wall = textures_path(copy, "SO");
	cub->s.we_wall = textures_path(copy, "WE");
	cub->s.ea_wall = textures_path(copy, "EA");
	if (!valid_texture(cub->s.so_wall) ||
				!valid_texture(cub->s.no_wall) ||
				!valid_texture(cub->s.ea_wall) ||
				!valid_texture(cub->s.we_wall))
	{

		free(cub->s.no_wall);
		free(cub->s.so_wall);
		free(cub->s.ea_wall);
		free(cub->s.we_wall);
	}
}