/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:04:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/24 14:42:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	put_pixel(t_params *params, int x, int y)
{
	if (y < params->map->size_y / 2)
		mlx_put_pixel(params->txt->ground, x, y, 0);
}

void	render_minimap(t_params *params)
{
	int	minimap_box_x;
	int	minimap_box_y;
	int	x;
	int	y;

	minimap_box_x = params->map->size_x / 4;
	minimap_box_y = params->map->size_y / 4;
	params->txt->minimap = mlx_new_image(params->mlx,
			minimap_box_x, minimap_box_y);
	x = 0;
	while (x < minimap_box_x)
	{
		y = 0;
		while (y < minimap_box_y)
		{
			put_pixel(params, x, y);
			y++;
		}
		x++;
	}
	mlx_image_to_window(params->mlx, params->txt->minimap, 0, 0);
}
