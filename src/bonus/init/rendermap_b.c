/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:34:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_distance_helper(t_params *params, t_ray *ray)
{
	ray->distance
		= sqrt(pow((params->map->player.x - ray->ray_pos.pos_x) / 90, 2)
			+ pow((params->map->player.y - ray->ray_pos.pos_y) / 90, 2));
	ray->distance = ray->distance * cos(M_PI / 180
			* (ray->ray_angle - params->map->player.angle));
	if (ray->distance <= 0)
		ray->distance = EPSILON;
	ray->wall_height = (int)params->map->size_y / ray->distance;
	ray->start_pos = params->map->size_y / 2 - ray->wall_height / 2;
	if (ray->start_pos < 0)
		ray->start_pos = 0;
	ray->end_pos = params->map->size_y / 2 + ray->wall_height / 2;
	if (ray->end_pos >= params->map->size_y)
		ray->end_pos = params->map->size_y - 1;
}

void	calculate_distance(t_params *params, t_ray *ray)
{
	int	x;
	int	y;

	while (ray->wall == 0)
	{
		ray->ray_pos.pos_x += ray->ray_cos;
		ray->ray_pos.pos_y += ray->ray_sin;
		x = ray->ray_pos.pos_x;
		y = ray->ray_pos.pos_y;
		if (params->map->map[x / 64][y / 64] == '1')
			ray->wall = 1;
		if (params->map->map[x / 64][y / 64] == '2')
			ray->wall = 2;
		if (params->map->map[x / 64][y / 64] == '3')
			ray->wall = 3;
		if (params->map->map[x / 64][y / 64] == '6')
			ray->wall = 4;
		if (params->map->map[x / 64][y / 64] >= 'a'
			&& params->map->map[x / 64][y / 64] <= 'z')
			ray->wall = 5 + params->map->map[x / 64][y / 64] - 'a';
	}
	calculate_distance_helper(params, ray);
	render_wall_line(params, ray, x, y);
}

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
	ray->half_fov = (double) params->map->fov / 2;
	ray->ray_increment = (double) params->map->fov
		/ (double) params->map->size_x;
	if (ray->ray_increment < EPSILON)
		ray->ray_increment = 60.0 / 1920.0;
	ray->ray_angle = params->map->player.angle - 30;
	ray->ray_count = 0;
	ray->gun_light = params->gun_state * 5;
	ray->global_light = params->global_light;
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
