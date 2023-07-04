/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:44:47 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_up_celling(t_params *params, int x, int y)
{
	int	offset;
	int	r;
	int	g;
	int	b;

	x = abs(params->map->size_x / 2 - x) / 2;
	y = params->map->size_y / 2 - abs(params->map->size_y / 2 - y);
	offset = sqrt(x * x + y * y) / 11;
	r = params->txt->c_r - offset;
	if (r < 0)
		r = 0;
	g = params->txt->c_g - offset;
	if (g < 0)
		g = 0;
	b = params->txt->c_b - offset;
	if (b < 0)
		b = 0;
	params->txt->celling = rgb(r, g, b, 255);
}

void	set_up_floor(t_params *params, int x, int y)
{
	int	offset;
	int	r;
	int	g;
	int	b;

	x = abs(params->map->size_x / 2 - x) / 2;
	y = params->map->size_y / 2 - abs(params->map->size_y / 2 - y);
	offset = sqrt(x * x + y * y);
	offset = offset / 11;
	r = params->txt->f_r - offset;
	if (r < 0)
		r = 0;
	g = params->txt->f_g - offset;
	if (g < 0)
		g = 0;
	b = params->txt->f_b - offset;
	if (b < 0)
		b = 0;
	params->txt->floor = rgb(r, g, b, 255);
}

void	skybox_logic(t_params *params, int x, int y)
{
	if (y < params->map->size_y / 2)
	{
		set_up_celling(params, x, y);
		mlx_put_pixel(params->txt->ground, x, y, params->txt->celling);
	}
	else
	{
		set_up_floor(params, x, y);
		mlx_put_pixel(params->txt->ground, x, y, params->txt->floor);
	}
}

void	render_skybox(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	params->txt->ground = mlx_new_image(params->mlx,
			params->map->size_x, params->map->size_y);
	while (x < params->map->size_x)
	{
		y = 0;
		while (y < params->map->size_y)
		{
			skybox_logic(params, x, y);
			y++;
		}
		x++;
	}
}
