/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/31 16:27:15 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

uint32_t	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_line(t_params *params, t_ray *ray, int32_t color)
{
	while (ray->ray_txt_seg_s < ray->ray_txt_seg_e)
	{
		mlx_put_pixel(params->txt->ground, ray->ray_count,
			ray->ray_txt_seg_s, color);
		ray->ray_txt_seg_s++;
	}
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}