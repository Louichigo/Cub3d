/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:46:46 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/20 14:00:44 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_validarg(int argc, char **argv)
{
	char	*extension;

	if (argc != 2)
	{
		printf("Error\nusage: ./cub3d '.cub file path'\n");
		return (false);
	}
	extension = &argv[1][ft_strlen(argv[1]) - 4];
	if (ft_strlen(argv[1]) < 4 || ft_strcmp(extension, ".cub") != 0)
	{
		printf("Error\nmap filename requires a .cub extension\n");
		return (false);
	}
	return (true);
}

int	open_fd(int argc, char **argv)
{
	int	fd;

	if (!check_validarg(argc, argv))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\ncould not open .cub file");
		return (-1);
	}
	return (fd);
}

int	fd_size(int argc, char **argv)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open_fd(argc, argv);
	if (fd < 0)
		return (-1);
	line = gnl_custom(fd);
	while (line != NULL)
	{
		free(line);
		line = gnl_custom(fd);
		size++;
	}
	close(fd);
	if (line)
		free(line);
	return (size);
}

char	**copy_fd(int argc, char **argv)
{
	int		fd;
	int		i;
	int		file_size;
	char	**copy;
	char	*line;

	fd = open_fd(argc, argv);
	if (fd < 0)
		exit(-1);
	file_size = fd_size(argc, argv);
	copy = (char **) malloc(sizeof(char *) * (file_size + 1));
	if (copy == NULL)
		exit(-1);
	i = 0;
	line = gnl_custom(fd);
	while (line != NULL)
	{
		copy[i] = line;
		line = gnl_custom(fd);
		i++;
	}
	copy[i] = NULL;
	close(fd);
	if (line)
		free(line);
	return (copy);
}
