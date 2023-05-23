/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/23 17:38:54 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
    return (r << 24 | g << 16 | b << 8);
}

void	test_textures(t_params *params)
{
	params->textures.ea = mlx_load_png("./textures/Test1.png");
	params->textures.so = mlx_load_png("./textures/Test2.png");
	params->textures.no = mlx_load_png("./textures/Test3.png");
	params->textures.we = mlx_load_png("./textures/Test4.png");
	params->textures.f_r = 1;
	params->textures.f_b = 200;
	params->textures.f_g = 3;
	params->textures.c_r = 255;
	params->textures.c_b = 255;
	params->textures.c_g = 0;
	params->map.size_x = 1920;
	params->map.size_y = 1080;
	params->textures.ground = mlx_new_image(params->mlx,
			params->map.size_x, params->map.size_y);
	params->textures.celling = ft_pixel(params->textures.c_b, params->textures.c_g, params->textures.c_r);
	params->textures.floor = ft_pixel(params->textures.f_b, params->textures.f_g, params->textures.f_r);
	// mlx_image_to_window(params->mlx, test1, 0, 0);
}

void	render_skybox(t_params *params)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	while (x < params->map.size_x)
	{
		y = 0;
		while (y < params->map.size_y)
		{
			if (y > params->map.size_y / 2)
				mlx_put_pixel(params->textures.ground, x, y, params->textures.celling);
			else
				mlx_put_pixel(params->textures.ground, x, y, params->textures.floor);
			y++;
		}
		x++;
	}
}

void	render_map(t_params *params)
{
	test_textures(params);
	render_skybox(params);
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
	mlx_loop(params->mlx);
}

//tocheckout add flexible map scaling
//todo add variables for the map size
//todo add flexible map size

int	init_cube(t_params *params)
{
	params->mlx = mlx_init(1920, 1080, "Cub3d", true);
	game_loop(params);
	return (0);
}
