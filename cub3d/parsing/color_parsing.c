/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:08:57 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/03 13:46:38 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	valid_value(char **color)
{
	int	i;
	int	j;
	int	rgb[3];

	i = -1;
	while (color[++i])
	{
		j = -1;
		while (color[i][++j])
		{
			if (!is_digit(color[i][j]))
			{
				printf("Error\nincorrect rgb color values: digits only pls\n");
				return (false);
			}
		}
		rgb[i] = ft_atoi(color[i]);
		if (is_rgb(rgb[i]) != true)
		{
			printf("Error\nincorrect rgb color values: range is 0 to 255\n");
			return (false);
		}
	}
	return (true);
}

bool	virgule_check(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
	{
		printf("Error\ncolor format is 'x, x, x'\n");
		return (false);
	}
	return (true);
}

char	*space_remover(char *str)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	trimmed = malloc(sizeof(char) * (ft_strlen(str) - space_counter(str) + 1));
	if (!trimmed)
		exit(-1);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		trimmed[j] = str[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

char	*color_strings(char **copy, char c)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == c)
			{
				j++;
				while (is_space(copy[i][j]) == true)
					j++;
				flag = j;
				while (is_space(copy[i][j]) == true || copy[i][j] != '\n')
					j++;
				return (ft_substr(copy[i], flag, j - flag));
			}
		}
	}
	return (NULL);
}

unsigned int	string_to_rgb(t_cub *cub, char **copy, char flag)
{
	int				i;

	cub->color_string = color_strings(copy, flag);
	if (cub->color_string == NULL)
	{
		printf("Error\ncolor settings for %c not found\n", flag);
		free(cub->color_string);
		exit(-1);
	}
	cub->color_cleanstring = space_remover(cub->color_string);
	free(cub->color_string);
	if (!virgule_check(cub->color_cleanstring))
		ft_error("rgb error in map");
	cub->color = ft_split(cub->color_cleanstring, ',');
	free(cub->color_cleanstring);
	if (!valid_value(cub->color))
		ft_error("rgb error in map");
	i = -1;
	while (cub->color[++i])
		cub->rgb[i] = ft_atoi(cub->color[i]);
	free_chartab(cub->color);
	cub->hexa_rgb = 0;
	cub->hexa_rgb = (cub->rgb[0] << 16 | cub->rgb[1] << 8 | cub->rgb[2]);
	return (cub->hexa_rgb);
}
