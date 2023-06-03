/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/03 14:45:13 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"

void	load_img(t_params *params)
{
	params->txt->pause_i = mlx_texture_to_image(params->mlx,
			params->txt->pause_t);
	mlx_image_to_window(params->mlx, params->txt->pause_i, 0, 0);
}

void	game_loop(t_params *params)
{
	load_img(params);
	if (params->pause != 1)
	{
		render_skybox(params);
		render_map(params);
		render_minimap(params);
	}
	mlx_loop_hook(params->mlx, &keyhook, params);
	mlx_key_hook(params->mlx, &escape, params);
	mlx_loop(params->mlx);
}

void	init_helper(t_params *p)
{
	p->map->door = mlx_load_png("textures/Door.png");
	p->map->def = mlx_load_png("textures/Test5.png");
	p->txt->pause_t = mlx_load_png("textures/hell_img.png");
	p->pause = 1;
	init_gun(p);
	spawn_doors(p);
}

void	init_settings(t_params *p)
{
	p->map->speed = SPEED;
	p->map->size_x = HEIGHT;
	p->map->size_y = WIDTH;
	p->map->minimap_box = MINIMAP_BOX;
	p->map->offset = OFFSET;
	p->map->fov = 66.0;
	p->fps = 0;
	p->map->total_width = p->map->map_height * 64;
	p->map->total_height = p->map->map_width * 64;
	p->map->player.x = p->map->player.map_x * 64;
	p->map->player.y = p->map->player.map_y * 64;
	init_helper(p);
}

int	init_cube(t_params *params)
{
	init_settings(params);
	system("afplay ./sound/music.mp3 &");
	params->mlx = mlx_init(1920, 1080, "Cub3d", false);
	game_loop(params);
	free(params->map->map);
	system("killall afplay");
	return (0);
}
