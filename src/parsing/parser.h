/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/05/23 15:29:07 by kvebers          ###   ########.fr       */
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
	int	size_x;
	int	size_y;
}	t_map;

typedef struct s_params
{
	char	**lines;
	
	mlx_t	*mlx;
}	t_params;


parse_error	parse(int argc, char **argv, t_params *params);

#endif