/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/31 09:48:11 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

uint32_t	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_line(t_params *params, t_ray *ray)
{
	while (ray->start_pos < ray->end_pos)
	{
		mlx_put_pixel(params->txt->ground, ray->ray_count,
			ray->start_pos, rgb(255, 0, 0, 255));
		ray->start_pos++;
	}
}
