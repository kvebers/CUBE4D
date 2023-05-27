/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:06:45 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/27 16:54:34 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

void	put_line(t_params *params, int x, float distance)
{
	int	yoffset;
	int	y;

	if (distance > params->map->size_y)
		distance = params->map->size_y;
	yoffset = (params->map->size_y - (int) distance) / 2;
	y = 0;
	while (y < distance)
	{
		mlx_put_pixel(params->txt->ground, x, y + yoffset, rgb(255, 0, 0, 255));
		y++;
	}
}

float	get_distance(int angle, t_params *params)
{
	int			cnt;
	t_vector	vector;
	t_vector	vector1;

	cnt = 0;
	vector = vector_estimation(1, angle);
	vector1.pos_x = params->map->player.x;
	vector1.pos_y = params->map->player.y;
	while (cnt < 10000)
	{
		vector1.pos_y = vector1.pos_y - vector.pos_y;
		vector1.pos_x = vector1.pos_x - vector.pos_x;
		if (check_cordinates(params, vector1.pos_x, vector1.pos_y) == 0)
		{
			return (sqrt((vector1.pos_x - params->map->player.x)
					* (vector1.pos_x - params->map->player.x)
					+ (vector1.pos_y - params->map->player.y)
					* (vector1.pos_y - params->map->player.y)));
		}
		cnt++;
	}
	return (0);
}


void	render_map(t_params *params)
{
	int		x;
	float	angle;
	float	distance;
	float	perpendicularDistance;
	float	wall_height;

	x = 0;
	while (x < params->map->size_x)
	{
		angle = params->map->player.angle - params->fov / 2
			+ (x * params->fov / params->map->size_x);
		distance = get_distance(angle, params);
		perpendicularDistance = fabs(distance * cos(angle * M_PI / 180 - params->map->player.angle));
		wall_height = (64 / perpendicularDistance) * params->map->size_y;
		put_line(params, x, wall_height);
		printf("%i %f\n", x, wall_height);
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
