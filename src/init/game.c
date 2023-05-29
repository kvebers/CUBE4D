/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/29 11:19:47 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include "../parsing/parser.h"

void	game_loop(t_params *params)
{
	render_skybox(params);
	render_map(params);
	render_minimap(params);
	mlx_key_hook(params->mlx, keyhook, params);
	mlx_loop(params->mlx);
}

void init_settings(t_params *p)
{
	p->map->player.angle = ANGLE;
	p->map->speed = SPEED;
	p->map->size_x = HEIGHT;
	p->map->size_y = WIDTH;
	p->map->minimap_box = MINIMAP_BOX;
	p->map->offset = OFFSET;
	p->map->height = count_lines(p->lines);
	p->map->width = get_longest_line(p->lines);
	p->map->total_width = p->map->width * 64;
	p->map->total_height = p->map->height * 64;
}

int	init_cube(t_params *params)
{
	params->mlx = mlx_init(1920, 1080, "Cub3d", true);
	init_settings(params);
	debug_info(params);
	// game_loop(params);
	free(params->map->map);
	return (0);
}
