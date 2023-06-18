/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 09:48:10 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/18 13:21:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

void	init_ray(t_params *params, t_ray *ray)
{
	ray->ray_pos.pos_x = params->map->player.x;
	ray->ray_pos.pos_y = params->map->player.y;
	ray->ray_radians = ray->ray_angle * M_PI / 180;
	ray->ray_cos = cos(ray->ray_radians);
	ray->ray_sin = sin(ray->ray_radians);
	ray->wall = 0;
}

void	init_ray_frame(t_params *params, t_ray *ray)
{
	ray->half_fov = (double)params->map->fov / 2;
	ray->ray_increment = (double)params->map->fov / (double)params->map->size_x;
	if (ray->ray_increment < EPSILON).
		ray->ray_increment = 60.0 / 1920.0;
	ray->ray_angle = params->map->player.angle - 30;
	ray->ray_count = 0;
}

void	calculate_distance_helper(t_params *params, t_ray *ray)
{
	ray->distance = sqrt(pow((params->map->player.x - ray->ray_pos.pos_x) / 90,
				2) + pow((params->map->player.y - ray->ray_pos.pos_y) / 90, 2))
				* cos(M_PI / 180 * (ray->ray_angle
				- params->map->player.angle));
	if (ray->distance <= 0)
		ray->distance = EPSILON;
	ray->wall_height = params->map->size_y / ray->distance;
	ray->start_pos = (int) params->map->size_y / 2 - ray->wall_height / 2;
	if (ray->start_pos < 0)
		ray->start_pos = 0;
	ray->end_pos =  (int)  params->map->size_y / 2 + ray->wall_height / 2;
	if (ray->end_pos >= params->map->size_y)
		ray->end_pos = params->map->size_y - 1;
}