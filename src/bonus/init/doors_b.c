/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:05:04 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:47:15 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	close_doors(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(64, params->map->player.angle);
	if (params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] == '4')
	{
		params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
			/ 64][(int)(vector.pos_y + params->map->player.y) / 64] = '2';
		mlx_delete_image(params->mlx, params->txt->ground);
		render_skybox(params);
		render_map(params);
		mlx_delete_image(params->mlx, params->txt->minimap);
		render_minimap(params);
		params->txt->ground->instances->z = 1;
		params->txt->minimap->instances->z = 3;
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
		mlx_delete_image(params->mlx, params->txt->ground);
		render_skybox(params);
		render_map(params);
		mlx_delete_image(params->mlx, params->txt->minimap);
		render_minimap(params);
		params->txt->ground->instances->z = 1;
		params->txt->minimap->instances->z = 3;
	}
	else
		close_doors(params);
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
			y++;
		}
		x++;
	}
}
