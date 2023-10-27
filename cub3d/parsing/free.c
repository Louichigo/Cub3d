/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:31:46 by cgross            #+#    #+#             */
/*   Updated: 2023/10/27 10:56:32 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	return (size);
}

void	free_chelou(t_cub *cub, char **map)
{
	free_chartab(map);
	free_tex(cub);
	ft_error("");
}

void	free_tex(t_cub *cub)
{
	free(cub->s.no_wall);
	free(cub->s.we_wall);
	free(cub->s.ea_wall);
	free(cub->s.so_wall);
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
