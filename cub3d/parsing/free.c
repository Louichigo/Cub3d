/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:31:46 by cgross            #+#    #+#             */
/*   Updated: 2023/10/25 12:47:37 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	return (size);
}

void	free_chartab(char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = tab_size(tab);
	while (i <= size)
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_mapint(t_data *s, int **map)
{
	int	h;

	h = 0;
	while (h < s->map_h)
	{
		free(map[h]);
		h++;
	}
	free(map);
}
