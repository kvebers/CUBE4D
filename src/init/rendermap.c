/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:34:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/18 13:24:43 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

void	ray_collison(t_params *params, t_ray *ray, int *x, int *y)
{
	ray->ray_pos.pos_x += ray->ray_cos;
	ray->ray_pos.pos_y += ray->ray_sin;
	*x = (int)ray->ray_pos.pos_x;
	*y = (int)ray->ray_pos.pos_y;
	if (params->map->map[*x / 64][*y / 64] == '1' && ray->wall != 2)
		ray->wall = 1;
}

void	calculate_distance(t_params *params, t_ray *ray)
{
	int	x;
	int	y;
	
	while (ray->wall == 0)
		ray_collison(params, ray, &x, &y);
	calculate_distance_helper(params, ray);
	render_wall_line(params, ray, x, y);
}

void	render_map(t_params *params)
{
	t_ray	ray;

	init_ray_frame(params, &ray);
	while (ray.ray_count < params->map->size_x)
	{
		init_ray(params, &ray);
		calculate_distance(params, &ray);
		ray.ray_angle = ray.ray_angle + ray.ray_increment;
		ray.ray_count++;
	}
	mlx_image_to_window(params->mlx, params->txt->ground, 0, 0);
}
