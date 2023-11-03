/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:47:49 by cgross            #+#    #+#             */
/*   Updated: 2023/11/03 13:47:05 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hauteur_map(char **copy)
{
	int	start;
	int	end;

	start = map_first_line(copy);
	if (start < 6)
	{
		printf("not enough args in .cub file\n");
		free_chartab(copy);
		exit(-1);
	}
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
			{
				if (i > 6)
					ft_error("Error\nduplicate or invalid parameters found\n");
				return (i);
			}
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
