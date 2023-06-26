/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:03:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/26 17:51:47 by kvebers          ###   ########.fr       */
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

mlx_texture_t	*fix_corners(t_params *params, int x, int y, t_ray *ray)
{
	(void) ray;
	if (x % 64 != 0 || x % 64 == 63)
		return (NULL);
	if (y % 64 != 0 || y % 64 == 63)
		return (NULL);
	if (x % 64 == 0 && params->map->map[x / 64][y / 64 - 1] == '1')
		return (params->txt->ea);
	if (x % 64 == 63 && params->map->map[x / 64][y / 64 + 1] == '1')
		return (params->txt->we);
    return (NULL);
}

mlx_texture_t	*texture_to_render(t_params *params, int x, int y, t_ray *ray)
{
	mlx_texture_t	*t;

	t = NULL;
	t = fix_corners(params, x, y, ray);
	if (t != NULL)
		return (t);
	if (x % 64 == 0)
		return (params->txt->we);
	if (x % 64 == 63)
		return (params->txt->ea);
	if (y % 64 == 63)
		return (params->txt->no);
	return (params->txt->so);
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
