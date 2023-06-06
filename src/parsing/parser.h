/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/06/06 04:31:43 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../cub3d.h"


# define VALID 0

# define INVALID 1

// typedef enum e_char *
// {
// 	VALID,
// 	INVALID,
// 	INVALID_NUM_ARGS,
// 	INVALID_ARG,
// 	INVALID_FILE,
// 	INVALID_IDENTIFIERS,
// 	MULT_RES_INPUT,
// 	MANY_RES_INPUT,
// 	INVALID_RES_INPUT,
// 	INVALID_HEIGHT,
// 	INVALID_WIDTH,
// 	MULT_FLOOR_INPUT,
// 	MANY_FLOOR_INPUT,
// 	INVALID_FLOOR_FORMAT,
// 	INVALID_FLOOR_VALUES,
// 	MULT_CEILING_INPUT,
// 	MANY_CEILING_INPUT,
// 	INVALID_CEILING_FORMAT,
// 	INVALID_CEILING_VALUES,
// 	INVALID_TXT_PATH,
// 	MULT_NORTH_INPUT,
// 	MULT_SOUTH_INPUT,
// 	MULT_WEST_INPUT,
// 	MULT_EAST_INPUT,
// 	INVALID_NORTH_PATH,
// 	INVALID_SOUTH_PATH,
// 	INVALID_WEST_PATH,
// 	INVALID_EAST_PATH,
// 	MAP_404,
// 	MAP_NOT_CLOSED,
// 	INVALID_FILE_EXTENSION,
// 	INIT_GAME_ERROR,
// }					char *;

// static char			*error_msgs[100] = {

// [INVALID_ARG] = "Error\nInvalid argument\n",
// [INVALID_FILE] = "Error\nInvalid file or wrong path\n",
// [INVALID_IDENTIFIERS] = ,
// [MULT_RES_INPUT] = "Error\nMultiple resolution inputs\n",
// [MANY_RES_INPUT] = "Error\nToo many resolution inputs\n",
// [INVALID_RES_INPUT] = "Error\nInvalid resolution input\n",
// [INVALID_HEIGHT] = "Error\nInvalid height\n",
// [INVALID_WIDTH] = "Error\nInvalid width\n",

// [MANY_FLOOR_INPUT] = "Error\nToo many floor inputs\n",

// [MULT_CEILING_INPUT] = "Error\nMultiple ceiling inputs\n",

// [INVALID_TXT_PATH] = "Error\nInvalid texture path\n",

// [MULT_NORTH_INPUT] = 
// [MULT_SOUTH_INPUT] = "Error\nMultiple south inputs\n",
// [MULT_WEST_INPUT] = "Error\nMultiple west inputs\n",
// [MULT_EAST_INPUT] = "Error\nMultiple east inputs\n",

// [INVALID_NORTH_PATH] =,
// [INVALID_SOUTH_PATH] = , [INVALID_WEST_PATH] = ,
// [INVALID_EAST_PATH] = ,

// [MAP_404] = "Error\nMap not found\n",
// [MAP_NOT_CLOSED] = ,
// [INVALID_FILE_EXTENSION] = ,
// [INIT_GAME_ERROR] = ,
// };

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
}					t_params;

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