/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:15:02 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/02 09:38:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(char *line, int start)
{
	int		i;
	int		len;
	char	*path;

	i = 0;
	len = 0;
	while (line[start + i++] && line[start] != ' ' && line[start] != '\n')
		len++;
	path = (char *)malloc(sizeof(char) * len + 1);
	if (!path)
		return (NULL);
	i = 0;
	while (line[start + i] && line[start + i] != ' ' && line[start + i] != '\n')
	{
		path[i] = line[start + i];
		i++;
	}
	path[i] = '\0';
	return (path);
}

char	*textures_path(char **copy, char *flag)
{
	int		i;
	int		j;
	char	*path;

	i = -1;
	path = NULL;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == flag[0] && copy[i][j + 1] == flag[1])
			{
				j = j + 2;
				while (is_space(copy[i][j] == true))
					j++;
				j++;
				path = get_path(copy[i], j);
				return (path);
			}
		}
	}
	return (NULL);
}

char	*valid_texture(char **copy, char *flag)
{
	int		fd;
	char	*path;

	path = textures_path(copy, flag);
	if (path == NULL)
	{
		printf("Error\ncould not find texture path for %s\n", flag);
		exit(-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\ncould not open texture file for %s", flag);
		exit(-1);
	}
	return (path);
}

void	set_textures(t_cub *cub, char **copy)
{
	cub->s.no_wall = valid_texture(copy, "NO");
	cub->s.so_wall = valid_texture(copy, "SO");
	cub->s.ea_wall = valid_texture(copy, "EA");
	cub->s.we_wall = valid_texture(copy, "WE");
}
