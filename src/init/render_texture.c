/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:03:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/04 02:13:21 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

int32_t	get_pixel_color(int x, int y, mlx_texture_t *texture)
{
	int32_t	red;
	int32_t	green;
	int32_t	blue;
	int32_t	transperent;

	red = texture->pixels[64 * 4 * y + 4 * x];
	green = texture->pixels[64 * 4 * y + 4 * x + 1];
	blue = texture->pixels[64 * 4 * y + 4 * x + 2];
	transperent = texture->pixels[64 * 4 * y + 4 * x + 3];
	return (rgb(red, green, blue, transperent));
}

mlx_texture_t	*texture_to_render(t_params *params, int x, int y)
{
	if (x % 64 == 0)
		return (params->txt->so);
	if (x % 64 == 63)
		return (params->txt->no);
	if (y % 64 == 0)
		return (params->txt->we);
	return (params->txt->ea);
}

void	render_wall_line_loop(t_params *params, t_ray *ray, int x,
		mlx_texture_t *t)
{
	int32_t	color;

	while (ray->r <= t->height)
	{
		if (ray->r == t->height)
			ray->ray_txt_seg_e = ray->end_pos;
		color = get_pixel_color(x, ray->r, t);
		draw_line(params, ray, color);
		if (ray->r != t->height && ray->ray_txt_seg_e > params->map->size_y)
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

	t = texture_to_render(params, x, y);
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
