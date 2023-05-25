/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:53:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/25 23:33:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	test_textures(t_params *params)
{
	params->txt = malloc(sizeof(t_textures));
	params->txt->ea = mlx_load_png("./textures/Test1.png");
	params->txt->so = mlx_load_png("./textures/Test2.png");
	params->txt->no = mlx_load_png("./textures/Test3.png");
	params->txt->we = mlx_load_png("./textures/Test4.png");
	params->txt->f_r = 200;
	params->txt->f_b = 200;
	params->txt->f_g = 100;
	params->txt->c_r = 100;
	params->txt->c_b = 250;
	params->txt->c_g = 255;
	params->map->size_x = 1920;
	params->map->size_y = 1080;
	params->map->minimap_box = params->map->size_y / 4;
	params->map->offset = params->map->size_y / 8;
	params->map->height = count_lines(params->lines);
	params->map->width = get_longest_line(params->lines);
	params->map->total_width = params->map->width * 64;
	params->map->total_height = params->map->height * 64;
	get_player_pos(params);
}
