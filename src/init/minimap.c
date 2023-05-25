/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:04:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/24 17:06:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	render_mini_map(t_params *params, int x, int y)
{
	mlx_put_pixel(params->txt->minimap, x, y, 600);
}

void	put_mini_pixel(t_params *params, int x, int y)
{
	if (params->map->size_y / 64 > y)
		mlx_put_pixel(params->txt->minimap, x, y, 255);
	else if (params->map->size_y / 4 - params->map->size_y / 64 < y)
		mlx_put_pixel(params->txt->minimap, x, y, 255);
	else if (params->map->size_y / 64 > x)
		mlx_put_pixel(params->txt->minimap, x, y, 255);
	else if (params->map->size_y / 4 - params->map->size_y / 64 < x)
		mlx_put_pixel(params->txt->minimap, x, y, 255);
	else
		render_mini_map(params, x, y);
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
			minimap_box_x, minimap_box_x);
	x = 0;
	while (x < minimap_box_y)
	{
		y = 0;
		while (y < minimap_box_y)
		{
			put_mini_pixel(params, x, y);
			y++;
		}
		x++;
	}
	mlx_image_to_window(params->mlx, params->txt->minimap,
		params->map->size_x - params->map->size_y / 4,
		params->map->size_y - params->map->size_y / 4);
}

	// mlx_image_t *test = mlx_texture_to_image(params->mlx, params->txt->no);
	// mlx_resize_image(test, 64, 64);
	// mlx_image_to_window(params->mlx, test, 0, 0);