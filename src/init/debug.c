/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:11:24 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/29 16:31:09 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	debug_ray(t_ray *ray)
{
	if (ray->x < 10)
	{
		printf("==================================");
		printf("x and camera: %i %f\n",ray->x, ray->camera_x);
		printf("Plane: %f %f\n", ray->c_p2d.pos_x, ray->c_p2d.pos_x);
		printf("Delta_dist: %f %f\n", ray->delta_dist.pos_x, ray->delta_dist.pos_y);
		printf("Directions: %f %f\n", ray->dir.pos_x, ray->dir.pos_x);
		printf("Wall distance: %f Wall Len: %d\n", ray->p_wall, ray->line_height);
	}
}
