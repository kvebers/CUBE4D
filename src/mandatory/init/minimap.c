/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:04:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/01 08:27:29 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	render_player(t_params *params)
{
	int	x;
	int	y;
	int	upper_border;
	int	size;

	size = params->map->size_y / 8;
	x = size / 4 * (-1);
	y = x;
	upper_border = x * (-1);
	while (x < upper_border)
	{
		y = upper_border * (-1);
		while (y < upper_border)
		{
			if (y * y + x * x < 100)
				mlx_put_pixel(params->txt->minimap, x + size, y + size,
					rgb(255, 0, 0, 255));
			y++;
		}
		x++;
	}
}

void	render_mini_map(t_params *params, int x, int y)
{
    int	new_x;
    int	new_y;

	new_x = x + params->map->player.x - params->map->offset;
	new_y = y + params->map->player.y - params->map->offset;
	if (new_x <= 0 || new_y <= 0)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
	else if (new_x >= params->map->total_width
		|| new_y >= params->map->total_height)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
	else if (params->map->map[new_x / 64][new_y / 64] != '1')
		mlx_put_pixel(params->txt->minimap, x, y, rgb(13, 13, 13, 255));
	else
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
}


void	put_mini_pixel(t_params *params, int x, int y)
{
	if (params->map->size_y / 64 > y)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
	else if (params->map->size_y / 4 - params->map->size_y / 64 < y)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
	else if (params->map->size_y / 64 > x)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
	else if (params->map->size_y / 4 - params->map->size_y / 64 < x)
		mlx_put_pixel(params->txt->minimap, x, y, rgb(64, 64, 64, 255));
}	

void	render_minimap(t_params *params)
{
	int	minimap_box_y;
	int	x;
	int	y;

	minimap_box_y = params->map->size_y / 4;
	params->txt->minimap = mlx_new_image(params->mlx,
			params->map->minimap_box, params->map->minimap_box);
	x = 0;
	while (x < minimap_box_y)
	{
		y = 0;
		while (y < minimap_box_y)
		{
			render_mini_map(params, x, y);
			put_mini_pixel(params, x, y);
			y++;
		}
		x++;
	}
	render_player(params);
	mlx_image_to_window(params->mlx, params->txt->minimap,
		params->map->size_x - params->map->size_y / 4,
		params->map->size_y - params->map->size_y / 4);
}
