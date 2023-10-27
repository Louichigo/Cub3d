/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:15:02 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/26 18:44:06 by lobertho         ###   ########.fr       */
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

bool	valid_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\ncould not open texture file");
		return (false);
	}
	return (true);
}
