/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:33:17 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/26 11:28:20 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_text(t_cub *cub)
{
	cub->tex.txt[0].img = mlx_xpm_file_to_image(cub->s.mlx, cub->s.so_wall,
			&(cub->tex.txt[0].jsp), &(cub->tex.txt[0].jsp));
	if (!cub->tex.txt[0].img)
		ft_error("error with texture SO");
	cub->tex.txt[1].img = mlx_xpm_file_to_image(cub->s.mlx, cub->s.no_wall,
			&(cub->tex.txt[1].jsp), &(cub->tex.txt[1].jsp));
	if (!cub->tex.txt[1].img)
		ft_error("error with texture NO");
	cub->tex.txt[2].img = mlx_xpm_file_to_image(cub->s.mlx, cub->s.ea_wall,
			&(cub->tex.txt[2].jsp), &(cub->tex.txt[2].jsp));
	if (!cub->tex.txt[2].img)
		ft_error("error with texture EA");
	cub->tex.txt[3].img = mlx_xpm_file_to_image(cub->s.mlx, cub->s.we_wall,
			&(cub->tex.txt[3].jsp), &(cub->tex.txt[3].jsp));
	if (!cub->tex.txt[3].img)
		ft_error("error with texture WE");
	get_text_addr(cub);
}

void	get_text_addr(t_cub *cub)
{
	cub->tex.txt[0].addr2 = (int *)mlx_get_data_addr(cub->tex.txt[0].img,
			&cub->tex.txt[0].bits_per_pixel, &cub->tex.txt[0].line_length,
			&cub->tex.txt[0].endian);
	cub->tex.txt[1].addr2 = (int *)mlx_get_data_addr(cub->tex.txt[1].img,
			&cub->tex.txt[1].bits_per_pixel, &cub->tex.txt[1].line_length,
			&cub->tex.txt[1].endian);
	cub->tex.txt[2].addr2 = (int *)mlx_get_data_addr(cub->tex.txt[2].img,
			&cub->tex.txt[2].bits_per_pixel, &cub->tex.txt[2].line_length,
			&cub->tex.txt[2].endian);
	cub->tex.txt[3].addr2 = (int *)mlx_get_data_addr(cub->tex.txt[3].img,
			&cub->tex.txt[3].bits_per_pixel, &cub->tex.txt[3].line_length,
			&cub->tex.txt[3].endian);
}

void	find_texture(t_cub *cub)
{
	if (cub->s.hitside == 0 && cub->s.raydirx >= 0)
		cub->s.texnb = 0;
	else if (cub->s.hitside == 0 && cub->s.raydirx < 0)
		cub->s.texnb = 1;
	else if (cub->s.hitside == 1 && cub->s.raydiry >= 0)
		cub->s.texnb = 2;
	else if (cub->s.hitside == 1 && cub->s.raydiry < 0)
		cub->s.texnb = 3;
	else
		cub->s.texnb = 0;
}

void	init_textures(t_cub *cub)
{
	cub->s.texnum = cub->s.mapl[cub->s.mapx][cub->s.mapy] - 1;
	if (cub->s.hitside == 0)
		cub->s.wallx = cub->s.posy + cub->s.walldist * cub->s.raydiry;
	else
		cub->s.wallx = cub->s.posx + cub->s.walldist * cub->s.raydirx;
	cub->s.wallx -= floor((cub->s.wallx));
	cub->s.texx = (int)(cub->s.wallx * (double)TEXWIDTH);
	if (cub->s.hitside == 0 && cub->s.raydirx > 0)
		cub->s.texx = TEXWIDTH - cub->s.texx - 1;
	if (cub->s.hitside == 1 && cub->s.raydiry < 0)
		cub->s.texx = TEXWIDTH - cub->s.texx - 1;
	cub->s.step = 1.0 * TEXHEIGHT / cub->s.lineheight;
	cub->s.texpos = (cub->s.drawstart - cub->s.h / 2
			+ cub->s.lineheight / 2) * cub->s.step;
}

void	textures(t_cub *cub, int x)
{
	int	y;
	int	lol;

	y = cub->s.drawstart - 1;
	find_texture(cub);
	init_textures(cub);
	while (++y <= cub->s.drawend)
	{
		cub->s.texy = (int)cub->s.texpos & (TEXHEIGHT - 1);
		cub->s.texpos += cub->s.step;
		lol = cub->s.texy * cub->tex.txt[cub->s.texnb].line_length
			/ 4 + cub->s.texx;
		if (y < HAUTEUR && x < LARGEUR)
		{
			cub->s.addr2[y * cub->s.line_length / 4
				+ x] = cub->tex.txt[cub->s.texnb].addr2[lol];
		}
	}
}
