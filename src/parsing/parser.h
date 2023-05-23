/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/05/23 17:33:57 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../cub3d.h"

typedef enum
{
	VALID,
	WRONG_NUM_ARGS,
	INVALID_ARG,
	INVALID_FILE,
} parse_error;

static char	*error_msgs[10] =
{
	[VALID]				=   "VALID",
	[WRONG_NUM_ARGS]	=   "Wrong number of arguments",
	[INVALID_FILE]		=   "Invalid map file or wrong path",
};

typedef struct s_map
{
	int32_t	size_x;
	int32_t	size_y;
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
}	t_textures;

typedef struct s_params
{
	char		**lines;
	t_textures	textures;
	mlx_t		*mlx;
	t_map		map;
}	t_params;


parse_error	parse(int argc, char **argv, t_params *params);

#endif