/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:05:04 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/20 12:14:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"

void	close_doors(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(64, params->map->player.angle);
	if (params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] == '4')
	{
		params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
			/ 64][(int)(vector.pos_y + params->map->player.y) / 64] = '2';
	}
}

void	open_doors(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(64, params->map->player.angle);
	if (params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] == '2')
	{
		params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
			/ 64][(int)(vector.pos_y + params->map->player.y) / 64] = '4';
	}
	else
		close_doors(params);
}

int		player_pos(t_params *params, int x, int y)
{
	if (sqrt(pow(params->map->player.x / 64 - x, 2) + pow(params->map->player.y / 64 - y, 2)) < 8)
		return (1);
	return (0);
}

void	spawn_doors(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	srand(time(0));
	while (x < params->map->map_height)
	{
		y = 0;
		while (y < params->map->map_width)
		{
			if (params->map->map[x][y] == '1' && rand() % 4 == 0)
					params->map->map[x][y] = '3';
			if (params->map->map[x][y] == '0' && rand() % 25 == 0)
					params->map->map[x][y] = '2';
			if (params->map->map[x][y] == '0' && rand() % 7 == 0)
					params->map->map[x][y] = '5';
			if (params->map->map[x][y] == '0' && rand() % 20 == 0
				&& player_pos(params, x, y) == 0)
					params->map->map[x][y] = '6';
			y++;
		}
		x++;
	}
}
