/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:17:57 by lobertho          #+#    #+#             */
/*   Updated: 2023/11/03 13:53:43 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT 123
# define RIGHT 124
# define LARGEUR 1080
# define HAUTEUR 720
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define PI 3.1415926535
# define MINIMAPSIZE 10
# define RADIUS 10

enum {
	ON_DESTROY = 17
};

typedef struct s_mapv
{
	double	x;
	double	y;
}				t_mapv;

typedef struct s_data {
	char	**mapl;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		h2;
	int		l2;
	int		*addr2;
	int		jsp;
	int		spawncount;
	int		map_h;
	int		map_l;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		roof_color;
	int		floor_color;
	int		drawstart;
	int		drawend;
	int		largeur;
	int		x;
	int		w;
	int		s;
	int		a;
	int		d;
	int		r;
	int		l;
	int		lineheight;
	int		hit;
	int		hitside;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		texnum;
	int		texnb;
	double	step;
	double	texpos;
	double	wallx;
	double	texx;
	double	texy;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	walldist;
	double	h;
	double	movespeed;
	double	rotspeed;
	char	*no_wall;
	char	*so_wall;
	char	*we_wall;
	char	*ea_wall;
}	t_data;

typedef struct s_text {
	t_data	txt[4];

}	t_text;

typedef struct s_cub {
	t_data			s;
	t_text			tex;
	char			**color;
	char			*color_string;
	char			*color_cleanstring;
	int				rgb[3];
	unsigned int	hexa_rgb;
	
}	t_cub;

//game
int				ft_kpress(int key, t_cub *cub);
int				ft_krelease(int key, t_cub *cub);
int				ft_error(char *str);
int				ft_exit(t_cub *cub);
int				ft_refresh(t_cub *cub);
int				ft_moove(t_cub *cub);
int				turnright(t_cub *cub);
int				turnleft(t_cub *cub);
int				moovead(t_cub *cub);
int				moovews(t_cub *cub);

void			my_mlx_pixel_put(t_cub *img, int x, int y, int color);
void			init_raycast(t_cub *cub);
void			cub3(t_cub *cub);
void			initcub(t_cub *cub);
void			init_directions(t_cub *cub);
void			dda_and_height(t_cub *cub);
void			draw_walls(t_cub *cub);
void			get_text(t_cub *cub);
void			get_text_addr(t_cub *cub);
void			textures(t_cub *cub, int x);
void			minimap(t_cub *cub);

size_t			ft_strlen(const char *s);

//parsing
char			**copy_fd(int argc, char **argv);
char			*gnl_custom(int fd);
int				ft_strcmp(char *s1, char *s2);
char			*textures_path(char **copy, char *flag);
bool			is_space(char c);
void			parsing(t_cub *cub, char **copy);
int				ft_atoi(const char *str);
bool			is_digit(char c);
bool			is_rgb(int rgb);
int				space_counter(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
unsigned int	string_to_rgb(t_cub *cub, char **copy, char flag);
char			**map_copy(t_cub *cub, char **copy);
char			*check_spawn(t_cub *cub, char *s, int h);
int				hauteur_map(char **copy);
int				map_first_line(char **copy);
int				largeur_map(char **copy);
char			*ft_strdup(char *s1, int max_len);
void			init_dir(t_cub *cub, char c, int h, int l);
void			init_pos(t_cub *cub, int h, int l);
void			free_chartab(char **tab);
int				tab_size(char **tab);
void			free_tex(t_cub *cub);
void			free_chelou(t_cub *cub, char **map);
bool			is_map_closed(char **map);
char			*valid_texture(char **copy, char *flag);
void			set_textures(t_cub *cub, char **copy);

#endif
