/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:22:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/02 22:01:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	spawn_duck(t_params *params, int x, int y)
{
	if (sqrt(pow(params->map->player.x - x * 64, 2)
			+ pow(params->map->player.x - x * 64, 2)) < 500)
		return ;
	params->duck->alive = 1;
	params->duck->speed = 1;
	params->duck->rot.pos_x = x * 64;
	params->duck->rot.pos_y = y * 64 + 32;
	params->duck->angle = calculate_atan(params->duck->rot.pos_x,
			params->duck->rot.pos_y,
			params->map->player.x, params->map->player.y);
}

void	calculate_enemy_distance(t_params *params, t_ray *ray)
{
	int	x;
	int	y;

	while (ray->wall == 0)
	{
		ray->ray_pos.pos_x += ray->ray_cos;
		ray->ray_pos.pos_y += ray->ray_sin;
		x = (int)ray->ray_pos.pos_x;
		y = (int)ray->ray_pos.pos_y;
		if (params->map->map[x / 64][y / 64] == '1')
			ray->wall = 1;
		if (params->map->map[x / 64][y / 64] == '2')
			ray->wall = 2;
		if (params->map->map[x / 64][y / 64] == '3')
			ray->wall = 3;
	}
	calculate_distance_helper(params, ray);
	render_wall_line(params, ray, x, y);
}

void	update_enemy(t_params *params)
{
	params->duck->angle = calculate_atan(params->duck->rot.pos_x,
			params->duck->rot.pos_y,
			params->map->player.x, params->map->player.y);
	printf("%f\n", params->duck->angle);
}

void	render_enemy(t_params *params, t_ray *ray)
{
	(void) params;
	(void) ray;
}
