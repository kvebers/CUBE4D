/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:44:47 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:37:56 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include <stdio.h>

void	render_skybox(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	params->txt->ground = mlx_new_image(params->mlx,
										params->map->size_x,
										params->map->size_y);
	params->txt->floor = rgb(params->txt->f_r,
								params->txt->f_g,
								params->txt->f_b,
								255);
	params->txt->celling = rgb(params->txt->c_r,
								params->txt->c_g,
								params->txt->c_b,
								255);
	while (x < params->map->size_x)
	{
		y = 0;
		while (y < params->map->size_y)
		{
			if (y < params->map->size_y / 2)
				mlx_put_pixel(params->txt->ground, x, y, params->txt->celling);
			else
				mlx_put_pixel(params->txt->ground, x, y, params->txt->floor);
			y++;
		}
		x++;
	}
}
