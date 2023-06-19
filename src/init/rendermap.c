/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:34:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/19 11:36:32 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

void choose_ray(t_params *params, t_ray *ray, int *x, int *y)
{
	if (sqrt(pow((params->map->player.x - ray->ray_pos.pos_x) / 90,
				2) + pow((params->map->player.y - ray->ray_pos.pos_y)
				/ 90, 2)) < sqrt(pow((params->map->player.x
				- ray->ray_pos1.pos_x) / 90, 2)
				+ pow((params->map->player.y - ray->ray_pos1.pos_y) / 90, 2)))
	{
		*x = (int) ray->ray_pos.pos_x;
		*y = (int) ray->ray_pos.pos_y;
	}
	else
	{
		ray->ray_pos.pos_x = ray->ray_pos1.pos_x;
		ray->ray_pos.pos_y = ray->ray_pos1.pos_y;
		*x = (int) ray->ray_pos1.pos_x;
		*y = (int) ray->ray_pos1.pos_y;
	}
				
}

void	ray_collison_y(t_params *params, t_ray *ray)
{
	if (ray->ray_sin == 0)
	{
		ray->wall = 1;
		ray->ray_pos1.pos_x = 2000000;
		ray->ray_pos1.pos_y = 2000000;
		return ;
	}
	else if (ray->ray_sin < 0)
	{
		ray->ray_pos1.pos_x = fmod(ray->ray_pos1.pos_y, 64) / ray->ray_sin * ray->ray_cos;
		ray->ray_pos1.pos_y = ray->ray_pos1.pos_y -  fmod(ray->ray_pos1.pos_y, 64) - 0.001;
	}
	else if (ray->ray_sin > 0)
	{
		ray->ray_pos1.pos_x = ray->ray_pos1.pos_y + 64.0 -  fmod(ray->ray_pos1.pos_y, 64) / ray->ray_sin * ray->ray_cos;
		ray->ray_pos1.pos_y = ray->ray_pos1.pos_y + (64.0 -  fmod(ray->ray_pos1.pos_y, 64) + 0.001);
	}
	check_collisions(params, ray, ray->ray_pos1.pos_x, ray->ray_pos1.pos_y);
	while (ray->wall != 1)
	{
		if (ray->ray_sin < 0)
		{
			ray->ray_pos1.pos_y = ray->ray_pos1.pos_y - 64.0;
			ray->ray_pos1.pos_x = 64 / ray->ray_sin * ray->ray_cos;
		}
		else
		{
			ray->ray_pos1.pos_y = ray->ray_pos1.pos_y + 64.0;
			ray->ray_pos1.pos_x = 64 / ray->ray_sin * ray->ray_cos;
		}
		check_collisions(params, ray, ray->ray_pos1.pos_x, ray->ray_pos1.pos_y);
	}
}


void	ray_collison_x(t_params *params, t_ray *ray)
{
	printf("I segfault here Ray x: %f, Ray, y: %f Cos: %f\n", ray->ray_pos.pos_x, ray->ray_pos.pos_y, ray->ray_cos);
	if (ray->ray_cos == 0)
	{
		ray->wall = 1;
		ray->ray_pos.pos_x = 2000000;
		ray->ray_pos.pos_y = 2000000;
		return ;
	}
	else if (ray->ray_cos < 0)
	{
		ray->ray_pos.pos_y = fmod(ray->ray_pos.pos_x, 64) / ray->ray_cos * ray->ray_sin;
		ray->ray_pos.pos_x = ray->ray_pos.pos_x -  fmod(ray->ray_pos.pos_x, 64) - 0.001;
	}
	else if (ray->ray_cos > 0)
	{
		ray->ray_pos.pos_y = ray->ray_pos.pos_y + 64.0 -  fmod(ray->ray_pos.pos_x, 64) / ray->ray_cos * ray->ray_sin;
		ray->ray_pos.pos_x = ray->ray_pos.pos_x + (64.0 -  fmod(ray->ray_pos.pos_x, 64) + 0.001);
	}
	printf("Ray x: %f, Ray, y: %f Cos: %f\n", ray->ray_pos.pos_x, ray->ray_pos.pos_y, ray->ray_cos);
	check_collisions(params, ray, ray->ray_pos.pos_x, ray->ray_pos.pos_y);
	while (ray->wall != 1)
	{
		if (ray->ray_cos < 0)
		{
			ray->ray_pos.pos_x = ray->ray_pos.pos_x - 64.0;
			ray->ray_pos.pos_y = 64 / ray->ray_cos * ray->ray_sin;
		}
		else
		{
			ray->ray_pos.pos_x = ray->ray_pos.pos_x + 64.0;
			ray->ray_pos.pos_y = 64 / ray->ray_cos * ray->ray_sin;
		}
		check_collisions(params, ray, ray->ray_pos.pos_x, ray->ray_pos.pos_y);
	}
	printf("Here: Ray x: %f, Ray, y: %f Cos: %f\n", ray->ray_pos.pos_x, ray->ray_pos.pos_y, ray->ray_cos);
}

void	calculate_distance(t_params *params, t_ray *ray)
{
	int x;
	int y;
	
	ray->wall = 0;
	ray_collison_x(params, ray);
	ray->wall = 0;
	ray_collison_y(params, ray);
	choose_ray(params, ray, &x, &y);
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
