/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:54:28 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/27 11:10:03 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**map_copy(t_cub *cub, char **copy)
{
	char	**map;
	int		start;
	int		h;

	start = map_first_line(copy);
	map = (char **)malloc(sizeof(char *) * cub->s.map_h + 1);
	if (!map)
		return (NULL);
	h = 0;
	while (h < cub->s.map_h)
	{
		map[h] = ft_strdup(copy[start + h], cub->s.map_l);
		map[h] = check_spawn(cub, map[h], h);
		if (map[h] == NULL)
			free_chelou(cub, map);
		h++;
	}
	map[h] = NULL;
	if (cub->s.spawncount == 0)
	{
		free_chelou(cub, map);
		ft_error("Error\nNo spawn point define in map");
	}
	return (map);
}

char	*check_spawn(t_cub *cub, char *s, int h)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '1' && s[i] != '0' && (s[i] == 'N'
				|| s[i] == 'S' || s[i] == 'E' || s[i] == 'W'))
		{
			cub->s.spawncount += 1;
			if (cub->s.spawncount > 1)
			{
				printf("Error in map\nMultiple spawn points\n");
				return (NULL);
			}
			init_dir(cub, s[i], h, i);
			s[i] = '0';
		}
		else if (s[i] != '1' && s[i] != '0' && s[i] != ' ')
		{
			printf("Error in map\n%c is not a valid charcater", s[i]);
			return (NULL);
		}
	}
	return (s);
}

int	hauteur_map(char **copy)
{
	int	start;
	int	end;

	start = map_first_line(copy);
	if (start < 6)
		return (-1);
	end = 0;
	while (copy[start++])
		end++;
	return (end);
}

int	map_first_line(char **copy)
{
	int	i;
	int	j;

	i = 5;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			while (is_space(copy[i][j]))
				j++;
			if (copy[i][j] == '1')
				return (i);
		}
	}
	ft_error("Error\nno map found!\n");
	return (-1);
}

int	largeur_map(char **copy)
{
	int	max_len;
	int	start;
	int	j;

	start = map_first_line(copy) - 1;
	if (start < 0)
		return (-1);
	max_len = 0;
	while (copy[++start])
	{
		j = -1;
		while (copy[start][++j])
			if (max_len < j)
				max_len = j;
	}
	return (max_len);
}
