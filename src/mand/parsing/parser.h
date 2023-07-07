/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/07/08 00:30:40 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_vector
{
	float			pos_x;
	float			pos_y;
}					t_vector;

typedef struct s_ray
{
	double			ray_angle;
	double			half_fov;
	double			distance;
	double			ray_increment;
	double			ray_cos;
	double			ray_sin;
	double			ray_radians;
	double			ray_perp;
	double			ray_txt_inc;
	double			ray_txt_seg_s;
	double			ray_txt_seg_e;
	t_vector		ray_pos;
	int				ray_count;
	unsigned int	offset;
	int				wall;
	int				wall_height;
	int				start_pos;
	int				end_pos;
	uint32_t		r;
}					t_ray;

typedef struct s_pos
{
	float			angle;
	float			map_x;
	float			map_y;
	float			x;
	float			y;
}					t_pos;

typedef struct s_map
{
	int				map_width;
	int				map_height;
	int32_t			size_x;
	int32_t			size_y;
	int				**map;
	int				total_width;
	int				total_height;
	int				offset;
	int				speed;
	int				minimap_box;
	double			fov;
	t_pos			player;
}					t_map;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int32_t			f_r;
	int32_t			f_b;
	int32_t			f_g;
	int32_t			c_r;
	int32_t			c_b;
	int32_t			c_g;
	int32_t			floor;
	int32_t			celling;
	mlx_image_t		*ground;
	mlx_image_t		*minimap;
	char			**buffer;
}					t_textures;

typedef struct s_params
{
	char			**lines;
	t_textures		*txt;
	t_map			*map;
	mlx_t			*mlx;
	bool			floor;
	bool			ceiling;
	bool			north;
	bool			south;
	bool			west;
	bool			east;
	void			*mem;
}					t_params;

int					parse(int argc, char **argv, t_params *params);

int					set_east(char *path, t_params *p);
int					set_west(char *path, t_params *p);
int					set_south(char *path, t_params *p);
int					set_north(char *path, t_params *p);
int					set_params(char c, char *str, t_params *p);
int					set_ceiling_txt(char *str, t_params *p);
int					set_floor_txt(char *str, t_params *p);

void				init_map(t_params *p, char **map);
void				parse_map(t_params *p, char **map);
bool				check_map(t_params *p, int x, int y, int **map);

int					init_player(t_params *p);
void				debug_info(t_params *params);
void				free_2d_array(void **array, int height);
void				cub_free(t_params p);

void				check_empty_line(t_params *p, char **map);
void				compute_map_width(t_params *p, char **map);
void				allocate_map(t_params *p);

char				**get_lines(int fd, t_params *p);
void				skip_whitespace(char **str);

#endif