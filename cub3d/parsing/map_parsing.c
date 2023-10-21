/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:54:28 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/21 19:33:07 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**map_copy(char **copy)
{
	char	**map;
	int		largeur;
	int		hauteur;
	int		start;
	int		h;

	hauteur = hauteur_map(copy);
	largeur = largeur_map(copy);
	start = map_first_line(copy);
	map = (char **)malloc(sizeof(int *) * hauteur);
	if (!map)
		return (NULL);
	h = -1;
	while (++h < hauteur)
		map[h] = ft_strdup(copy[start + h], largeur + 1);
	map[h] = NULL;
	return (map);
}

int	**map_init(t_cub *cub, char **map_c)
{
	int	h;
	int	l;
	int	**map;

	map = (int **)malloc(sizeof(int *) * cub->s.map_h);
	if (!map)
		return (NULL);
	h = -1;
	while (++h < cub->s.map_h)
	{
		l = -1;
		map[h] = (int *)malloc(sizeof(int *) * cub->s.map_l);
		while (++l < cub->s.map_l && map_c[h][l] != '\n')
		{
			if (map_c[h][l] == '1')
				map[h][l] = 1;
			else if (map_c[h][l] == '0')
				map[h][l] = 0;
			else
			{
				map[h][l] = 0;
				//init_dir(cub, map_c[h][l]);
				cub->s.posx = (h + 0.5);
				cub->s.posy = (l + 0.5);
			}
		}
	}
	return (map);
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
	printf("Error\nno map found\n");
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
