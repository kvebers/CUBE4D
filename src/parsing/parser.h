/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/05/24 17:36:14 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../cub3d.h"
# include "../../libs/MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>

typedef enum {
	VALID,
	INVALID_NUM_ARGS,
	INVALID_ARG,
	INVALID_FILE,
	INVALID_IDENTIFIERS,
	MULT_RES_INPUT,
	MANY_RES_INPUT,
	INVALID_RES_INPUT,
	INVALID_HEIGHT,
	INVALID_WIDTH,
	MULT_FLOOR_INPUT,
	MANY_FLOOR_INPUT,
	INVALID_FLOOR_FORMAT,
	INVALID_FLOOR_VALUES,
	MULT_CEILING_INPUT,
	MANY_CEILING_INPUT,
	INVALID_CEILING_FORMAT,
	INVALID_CEILING_VALUES,
	INVALID_TXT_PATH,
	MULT_NORTH_INPUT,
	MULT_SOUTH_INPUT,
	MULT_WEST_INPUT,
	MULT_EAST_INPUT,
	INVALID_NORTH_PATH,
	INVALID_SOUTH_PATH,
	INVALID_WEST_PATH,
	INVALID_EAST_PATH,
	MAP_404,	
} parse_error;

static char *error_msgs[100]	= {
	[VALID]						=	"VALID",
	[INVALID_NUM_ARGS]			=	"Wrong number of arguments",
	[INVALID_ARG]				=	"Invalid argument",
	[INVALID_FILE]				=	"Invalid map file or wrong path",
	[INVALID_IDENTIFIERS]		=	"Invalid identifiers",
	[MULT_RES_INPUT]			=	"Multiple resolution inputs",
	[MANY_RES_INPUT]			=	"Too many resolution inputs",
	[INVALID_RES_INPUT]			=	"Invalid resolution input",
	[INVALID_HEIGHT]			=	"Invalid height",
	[INVALID_WIDTH]				=	"Invalid width",
	[MULT_FLOOR_INPUT]			=	"Multiple floor inputs",
	[MANY_FLOOR_INPUT]			=	"Too many floor inputs",
	[INVALID_FLOOR_FORMAT]		=	"Invalid floor format",
	[INVALID_FLOOR_VALUES]		=	"Invalid floor values",
	[MULT_CEILING_INPUT]		=	"Multiple ceiling inputs",
	[MANY_CEILING_INPUT]		=	"Too many ceiling inputs",
	[INVALID_CEILING_FORMAT]	=	"Invalid ceiling format",
	[INVALID_CEILING_VALUES]	=	"Invalid ceiling values",
	[INVALID_TXT_PATH]			=	"Invalid texture path",
	[MULT_NORTH_INPUT]			=	"Multiple north inputs",
	[MULT_SOUTH_INPUT]			=	"Multiple south inputs",
	[MULT_WEST_INPUT]			=	"Multiple west inputs",
	[MULT_EAST_INPUT]			=	"Multiple east inputs",
	[INVALID_NORTH_PATH]		=	"Invalid north path",
	[INVALID_SOUTH_PATH]		=	"Invalid south path",
	[INVALID_WEST_PATH]			=	"Invalid west path",
	[INVALID_EAST_PATH]			=	"Invalid east path",
	[MAP_404]					=	"Map not found",
	
};


typedef struct s_map
{
	int32_t	size_x;
	int32_t	size_y;
	int		**map;
	int		width;
	int		height;
}	t_map;

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
} t_params;

/* parser.c */
parse_error	parse(int argc, char **argv, t_params *params);


/* check_texture.c */
parse_error		set_ceiling(char *str, t_params *p);
parse_error		set_floor(char *str, t_params *p);

#endif