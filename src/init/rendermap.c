/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:06:45 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/27 12:21:23 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

void	put_line(t_params *params, int x, float offset)
{
	int	y;

	// if (offset < params->fov && offset > 0)
	// 	y = offset / params->fov * 1080;
	// else
	// 	y = 0;
	y = 0;
	printf("%f\n", offset);
	while (y < params->map->size_y - offset)
	{
		mlx_put_pixel(params->txt->ground, x, y, rgb(255, 0, 0, 255));
		y++;
	}
}

float	get_tangent(float distance)
{
	if (distance == -1 || distance == 0)
		return (0);
	return (atan(64 / distance) * 180 / M_PI);
}


float	get_distance(int angle, t_params *params)
{
	int			cnt;
	t_vector	vector;
	t_vector	vector1;

	cnt = 0;
	vector = vector_estimation(1, angle);
	vector1.pos_x = vector.pos_x;
	vector1.pos_y = vector.pos_y;
	while (cnt < 10000)
	{
		if (check_cordinates(params, vector1.pos_x, vector1.pos_x) == 0)
			return (sqrt(vector1.pos_x * vector1.pos_x + vector1.pos_y * vector1.pos_y));
		vector1.pos_y = vector1.pos_y + vector.pos_y;
		vector1.pos_x = vector1.pos_x + vector.pos_x;
		cnt++;
	}
	return (-1);
}


void	render_map(t_params *params)
{
	float	x;
	float	angle;
	float	distance;
	float	get_offset;

	x = params->map->size_x / (-2);
	while (x < params->map->size_x / 2)
	{
		angle = params->fov / x + params->map->player.angle;
		distance = get_distance(angle, params);
		get_offset = get_tangent(distance);
		put_line(params, x + params->map->size_x / 4, get_offset);
		//printf("%f %f %i\n",distance, angle, get_offset);
		x++;
	}
	mlx_image_to_window(params->mlx, params->txt->ground, 0, 0);
}

void	render_skybox(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	params->txt->ground = mlx_new_image(params->mlx,
			params->map->size_x, params->map->size_y);
	params->txt->floor = rgb(params->txt->f_r,
			params->txt->f_g, params->txt->f_b, 255);
	params->txt->celling = rgb(params->txt->c_r,
			params->txt->c_g, params->txt->c_b, 255);
	while (x < params->map->size_x)
	{
		y = 0;
		while (y < params->map->size_y)
		{
			if (y < params->map->size_y / 2)
				mlx_put_pixel(params->txt->ground, x, y, params->txt->floor);
			else
				mlx_put_pixel(params->txt->ground, x, y, params->txt->celling);
			y++;
		}
		x++;
	}
}
