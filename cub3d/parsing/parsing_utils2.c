/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:11:38 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/27 11:07:09 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_rgb(int rgb)
{
	if (rgb >= 0 && rgb <= 255)
		return (true);
	return (false);
}

int	space_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(char *s1, int max_len)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * max_len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] == ' ')
		dup[i++] = ' ';
	while (i < len && s1[i] != '\n' && s1[i] && i < max_len)
	{
		dup[i] = s1[i];
		i++;
	}
	while (i < max_len)
		dup[i++] = ' ';
	dup[i] = '\0';
	return (dup);
}

void	init_dir(t_cub *cub, char c, int h, int l)
{
	init_pos(cub, h, l);
	if (c == 'N')
	{
		cub->s.dirx = -1;
		cub->s.diry = 0;
		cub->s.planey = 0.66;
	}
	else if (c == 'S')
	{
		cub->s.dirx = 1;
		cub->s.diry = 0;
		cub->s.planey = -0.66;
	}
	else if (c == 'E')
	{
		cub->s.dirx = 0;
		cub->s.diry = 1;
		cub->s.planex = 0.66;
	}
	else if (c == 'W')
	{
		cub->s.dirx = 0;
		cub->s.diry = -1;
		cub->s.planex = -0.66;
	}
}
