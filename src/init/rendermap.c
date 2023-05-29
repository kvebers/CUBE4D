/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:06:45 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/29 15:35:35 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

void	draw_line(t_params *params, t_ray *ray)
{
	while (ray->draw_start < ray->draw_end)
	{
		mlx_put_pixel(params->txt->ground, ray->x, ray->draw_start, rgb(255, 0, 0, 255));
		ray->draw_start++;
	}
}

void	calculate_wall_dist(t_params *params, t_ray *ray)
{
	if (ray->side == 0)
		ray->p_wall = ray->side_step.pos_x - ray->delta_dist.pos_x;
	else
		ray->p_wall = ray->side_step.pos_y - ray->delta_dist.pos_y;
	ray->line_height = (int)params->map->size_y / ray->p_wall;
	ray->draw_start = -ray->line_height / 2 + params->map->size_y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + params->map->size_y / 2;
	if (ray->draw_start > params->map->size_y)
		ray->draw_end = params->map->size_y - 1;
}

void	dda(t_params *params, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_step.pos_x < ray->side_step.pos_y)
		{
			ray->side_step.pos_x += ray->delta_dist.pos_x;
			ray->player.pos_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_step.pos_y += ray->delta_dist.pos_y;
			ray->player.pos_y += ray->step_y;
			ray->side = 1;
		}
		if (check_cordinates(params, ray->player.pos_x, ray->player.pos_x) == 0)
			ray->hit = 1;
	}
}

void	step_side_dist(t_params *params, t_ray *ray)
{
	if (ray->dir.pos_x < 0)
	{
		ray->step_x = -1;
		ray->side_step.pos_x = (ray->player.pos_x - params->map->player.x)
			* ray->delta_dist.pos_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_step.pos_x = (ray->player.pos_x - params->map->player.x + 1)
			* ray->delta_dist.pos_x;
	}
	if (ray->dir.pos_y < 0)
	{
		ray->step_y = -1;
		ray->side_step.pos_y = (ray->player.pos_y - params->map->player.y)
			* ray->delta_dist.pos_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_step.pos_y = (ray->player.pos_y - params->map->player.y + 1)
			* ray->delta_dist.pos_y;
	}
}

void	init_ray(t_params *params, t_ray *ray)
{
	ray->hit = 0;
	ray->side = 0;
	ray->player.pos_x = (int)params->map->player.x;
	ray->player.pos_y = (int)params->map->player.y;
	ray->camera_x = ray->x * 2 / (double)params->map->size_x - 1;
	ray->dir.pos_x = ray->v_angle.pos_x + ray->c_p2d.pos_x * ray->camera_x;
	ray->dir.pos_y = ray->v_angle.pos_y + ray->c_p2d.pos_y * ray->camera_x;
	ray->delta_dist.pos_x = fabs(1 / ray->dir.pos_x);
	ray->delta_dist.pos_y = fabs(1 / ray->dir.pos_y);
	if (ray->dir.pos_x < EPSILON && ray->dir.pos_x > -EPSILON)
		ray->delta_dist.pos_x = 1;
	if (ray->dir.pos_y < EPSILON && ray->dir.pos_y > -EPSILON)
		ray->delta_dist.pos_y = 1;
}

void	init_ray_const(t_params *params, t_ray *ray)
{
	ray->c_plane = 0.66;
	ray->angle = params->map->player.angle;
	ray->angle_rad = ray->angle * M_PI / 180;
	ray->v_angle.pos_x = cos(ray->angle_rad);
	ray->v_angle.pos_y = sin(ray->angle_rad);
	ray->c_p2d.pos_x = ray->v_angle.pos_y;
    ray->c_p2d.pos_y = ray->v_angle.pos_x;
	ray->x = 0;
}

void	render_map(t_params	*params)
{
	t_ray	ray;

	init_ray_const(params, &ray);
	while (ray.x < params->map->size_x)
	{
		init_ray(params, &ray);
		step_side_dist(params, &ray);
		dda(params, &ray);
		calculate_wall_dist(params, &ray);
		draw_line(params, &ray);
		ray.x++;
	}
	mlx_image_to_window(params->mlx, params->txt->ground, 0, 0);
}

void	render_skybox(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	params->txt->ground = mlx_new_image(params->mlx,
			params->map->size_x, params->map->size_y);
	params->txt->floor = rgb(params->txt->f_r,
			params->txt->f_g, params->txt->f_b, 255);
	params->txt->celling = rgb(params->txt->c_r,
			params->txt->c_g, params->txt->c_b, 255);
	while (x < params->map->size_x)
	{
		y = 0;
		while (y < params->map->size_y)
		{
			if (y < params->map->size_y / 2)
				mlx_put_pixel(params->txt->ground, x, y, params->txt->floor);
			else
				mlx_put_pixel(params->txt->ground, x, y, params->txt->celling);
			y++;
		}
		x++;
	}
}
