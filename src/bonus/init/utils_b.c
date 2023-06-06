/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:50:34 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

uint32_t	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_line(t_params *params, t_ray *ray, int32_t color)
{
	while (ray->ray_txt_seg_s < ray->ray_txt_seg_e)
	{
		if (ray->ray_txt_seg_s >= 0)
		{
			mlx_put_pixel(params->txt->ground, ray->ray_count,
				ray->ray_txt_seg_s, color);
		}
		ray->ray_txt_seg_s++;
	}
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

double	calculate_atan(int x_enemy, int y_enemy, int x_player, int y_player)
{
	double	x;
	double	y;
	double	angle;

	x = abs(x_enemy - x_player);
	y = abs(y_enemy - y_player);
	angle = atan(y / x);
	angle = angle * 180 / M_PI;
	return (angle);
}