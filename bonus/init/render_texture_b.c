/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:03:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/26 12:49:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

int32_t	get_pixel_color(int x, int y, mlx_texture_t *texture, t_ray *ray)
{
	int32_t	red;
	int32_t	green;
	int32_t	blue;
	int32_t	transperent;

	red = texture->pixels[64 * 4 * y + 4 * x];
	green = texture->pixels[64 * 4 * y + 4 * x + 1];
	blue = texture->pixels[64 * 4 * y + 4 * x + 2];
	transperent = texture->pixels[64 * 4 * y + 4 * x + 3];
	shaders(&red, &green, &blue, ray);
	return (rgb(red, green, blue, transperent));
}

mlx_texture_t	*fix_corners(t_params *params, int x, int y, t_ray *ray)
{
	if (x % 64 == 63 && y % 64 == 63)
	{
		if (ray->ray_angle >= 45 && ray->ray_angle < 135)
			return (params->txt->no);
	}
	if (x % 64 == 0 && y % 64 == 0)
	{
		if (ray->ray_angle >= 135 && ray->ray_angle < 225)
			return (params->txt->ea);
	}
	if (x % 64 == 63 && y % 64 == 0)
	{
		if (ray->ray_angle >= 225 && ray->ray_angle < 315)
			return (params->txt->we);
	}
	if (x % 64 == 0 && y % 64 == 63)
	{
		if ((ray->ray_angle >= 315 && ray->ray_angle <= 360) || (ray->ray_angle >= 0 && ray->ray_angle < 45))
			return (params->txt->so);
	}
	return (NULL);
}

mlx_texture_t	*texture_to_render(t_params *params, int x, int y, t_ray *ray)
{
	mlx_texture_t	*t;

	t = NULL;
	if (ray->wall == 1)
		return (params->map->def);
	if (ray->wall == 2)
		return (params->map->door);
	if (ray->wall == 4 && params->fps % 2 == 0)
		return (params->txt->static_enemy1);
	if (ray->wall == 4 && params->fps % 2 == 1)
		return (params->txt->static_enemy2);
	if (ray->wall > 4)
		return (params->txt->enemy[ray->wall - 5]);
	t = fix_corners(params, x, y, ray);
	if (t != NULL)
		return (t);
	if (x % 64 == 0)
		return (params->txt->so);
	if (x % 64 == 63)
		return (params->txt->no);
	if (y % 64 == 0)
		return (params->txt->we);
	return (params->txt->ea);
}

void	render_wall_line_loop(t_params *params, t_ray *ray,
		int x, mlx_texture_t *t)
{
	int32_t		color;

	while (ray->r <= t->height)
	{
		if (ray->r == t->height)
			ray->ray_txt_seg_e = ray->end_pos;
		color = get_pixel_color(x, ray->r, t, ray);
		draw_line(params, ray, color);
		if (ray->r != t->height
			&& ray->ray_txt_seg_e > params->map->size_y)
			break ;
		ray->ray_txt_seg_e = ray->ray_txt_seg_e + ray->ray_txt_inc;
		if (ray->ray_txt_seg_e > params->map->size_y)
			ray->ray_txt_seg_e = params->map->size_y;
		ray->r++;
	}
}

void	render_wall_line(t_params *params, t_ray *ray, int x, int y)
{
	mlx_texture_t	*t;

	t = NULL;
	t = texture_to_render(params, x, y, ray);
	ray->r = 0;
	ray->ray_txt_inc = ((double)ray->wall_height
			/ (double)params->txt->no->height);
	ray->ray_txt_seg_s = params->map->size_y / 2 - ray->wall_height / 2;
	ray->ray_txt_seg_e = ray->ray_txt_seg_s + ray->ray_txt_inc;
	x = x % 64;
	if (x == 0 || x == 63)
		x = y % 64;
	render_wall_line_loop(params, ray, x, t);
}
