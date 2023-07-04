/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 10:00:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../parsing/parser.h"
#include "init.h"
#include <stdio.h>

void	game_loop(t_params *params)
{
	render_skybox(params);
	render_map(params);
	render_minimap(params);
	mlx_key_hook(params->mlx, keyhook, params);
	mlx_loop(params->mlx);
}

void	init_settings(t_params *p)
{
	p->map->speed = SPEED;
	p->map->size_x = HEIGHT;
	p->map->size_y = WIDTH;
	p->map->minimap_box = MINIMAP_BOX;
	p->map->offset = OFFSET;
	p->map->fov = 66.0;
	p->map->total_width = p->map->map_height * 64;
	p->map->total_height = p->map->map_width * 64;
	p->map->player.x = p->map->player.map_x * 64;
	p->map->player.y = p->map->player.map_y * 64;
}

int	init_cube(t_params *params)
{
	init_settings(params);
	params->mlx = mlx_init(1920, 1080, "Cub3d", false);
	game_loop(params);
	return (0);
}
