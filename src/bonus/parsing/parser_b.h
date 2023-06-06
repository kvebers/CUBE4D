/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_b.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/06/06 20:58:51 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d_bonus.h"


# define VALID 0

# define INVALID 1

typedef struct s_vector
{
	float	pos_x;
	float	pos_y;
}	t_vector;

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
	int				global_light;
	int				wall;
	int				gun_light;
	int				wall_height;
	int				start_pos;
	int				end_pos;
	uint32_t		r;
}	t_ray;

typedef struct s_pos
{
	float 	angle;
	float 	map_x; /* player position in 2dmap*/
	float	map_y;
	float	x;
	float	y;
}	t_pos;

typedef struct s_map
{
	int 		map_width; /* size of map in 2d format */
	int 		map_height; /* size of map in 2d format */
	int32_t		size_x; /* size of map in pixels aka HEIGHT */
	int32_t	size_y; /* size of map in pixels aka WIDTH */
	int		**map;
	int		total_width; 
	int		total_height;
	int		offset;
	int		speed;
	int		minimap_box;
	double	fov;
	mlx_texture_t	*def;
	mlx_texture_t	*door;
	t_pos	player;
}	t_map;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*gun0;
	mlx_texture_t	*gun1;
	mlx_texture_t	*gun2;
	mlx_texture_t	*gun3;
	mlx_texture_t	*pause_t;
	int32_t			f_r;
	int32_t			f_b;
	int32_t			f_g;
	int32_t			c_r;
	int32_t			c_b;
	int32_t			c_g;
	int32_t			floor;
	int32_t			celling;
	mlx_image_t		*pause_i;
	mlx_image_t		*ground;
	mlx_image_t		*minimap;
	mlx_image_t		*gun;
	char			**buffer;
}	t_textures;

typedef struct s_params {
	char		**lines;
	t_textures	*txt;
	t_map		*map;
	mlx_t		*mlx;
	bool		floor;
	bool		ceiling;
	bool		north;
	bool		south;
	bool		west;
	bool		east;
	bool		start;
	int			pause;
	int			gunx;
	int			guny;
	int			global_light;
	int			gun_state;
	uint32_t	fps;
}	t_params;

/* parser.c */

/* parser.c */
int					parse(int argc, char **argv, t_params *params);

/* check_texture.c */
int					set_params(char c, char *str, t_params *p);
int					set_east(char *path, t_params *p);
int					set_west(char *path, t_params *p);
int					set_south(char *path, t_params *p);
int					set_north(char *path, t_params *p);
int					set_ceiling_txt(char *str, t_params *p);
int					set_floor_txt(char *str, t_params *p);

void				init_map(t_params *p, char **map);
void				parse_map(t_params *p, char **map);
bool				check_map(t_params *p, int x, int y, int **map);

int					init_player(t_params *p);
void				print_map(t_params *p, char **map);
void				debug_info(t_params *params);
void				free_2d_array(void **array, int height);

#endif