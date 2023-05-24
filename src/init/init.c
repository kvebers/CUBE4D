/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/24 11:43:12 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	render_skybox(t_params *params)
{
	int	x;
	int	y;

	x = 0;
	params->txt->ground = mlx_new_image(params->mlx,
	 	params->map->size_x, params->map->size_y);
	params->txt->floor = rgb(params->txt->f_r, params->txt->f_b, params->txt->f_g, 255);
	params->txt->celling = rgb(params->txt->c_r, params->txt->c_b, params->txt->c_g, 255);
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

void	test_textures(t_params *params)
{
	params->txt = malloc(sizeof(t_textures));
	params->txt->ea = mlx_load_png("./textures/Test1.png");
	params->txt->so = mlx_load_png("./textures/Test2.png");
	params->txt->no = mlx_load_png("./textures/Test3.png");
	params->txt->we = mlx_load_png("./textures/Test4.png");
	params->txt->f_r = 1;
	params->txt->f_b = 200;
	params->txt->f_g = 3;
	params->txt->c_r = 255;
	params->txt->c_b = 255;
	params->txt->c_g = 0;
	params->map = malloc(sizeof(t_map));
	params->map->size_x = 1920;
	params->map->size_y = 1080;
}

void	render_map(t_params *params)
{
	(void) params;
}

//render minimap is bonus, probably should be seperate, but for now i will leave it here

void	render_minimap(t_params *params)
{
	(void) params;
}

void	game_loop(t_params *params)
{
	render_map(params);
	render_minimap(params);
	// mlx_key_hook(params->mlx, )
	printf("I was here");
	mlx_loop(params->mlx);
}

//tocheckout add flexible map scaling
//@todo add variables for the map size
//@todo add flexible map size

int	init_cube(t_params *params)
{
	test_textures(params);
	params->mlx = mlx_init(1920, 1080, "Cub3d", true);
	render_skybox(params);
	mlx_image_to_window(params->mlx, params->txt->ground, 0, 0);
	game_loop(params);
	return (0);
}
