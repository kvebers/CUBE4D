/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:51:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/20 14:05:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	destroy_enemy(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(64, params->map->player.angle);
	if (params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] == '6'
		|| params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] > 'a')
	{
		params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
			/ 64][(int)(vector.pos_y + params->map->player.y) / 64] = '0';
	}
	vector = vector_estimation(128, params->map->player.angle);
	if (params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] == '6'
		|| params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
		/ 64][(int)(vector.pos_y + params->map->player.y) / 64] > 'a')
	{
		params->map->map[(int)(vector.pos_x + (int)params->map->player.x)
			/ 64][(int)(vector.pos_y + params->map->player.y) / 64] = '0';
	}
}

void	render_gun(t_params *params)
{
	if (params->gun_state == 0)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun0);
	else if (params->gun_state == 1 || params->gun_state == 6)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun3);
	else if (params->gun_state == 2 || params->gun_state == 5)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun2);
	else if (params->gun_state == 3 || params->gun_state == 4)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun1);
	mlx_image_to_window(params->mlx, params->txt->gun,
		params->gunx + 10, params->guny + 10);
	if (params->gun_state == 4)
		destroy_enemy(params);
	params->gunx = 0;
	params->guny = 0;
	if (params->gun_state == 4)
		system("afplay ./sound/Gunfire.mp3 &");
	if (params->gun_state > 0)
		params->gun_state--;
}

void	init_gun(t_params *params)
{
	params->gunx = 0;
	params->guny = 0;
	params->gun_state = 0;
	params->txt->gun0 = mlx_load_png("textures/gun0.png");
	params->txt->gun1 = mlx_load_png("textures/gun1.png");
	params->txt->gun2 = mlx_load_png("textures/gun2.png");
	params->txt->gun3 = mlx_load_png("textures/gun3.png");
}

void	gun_stuff(t_params *params)
{
	mlx_delete_image(params->mlx, params->txt->gun);
	render_gun(params);
	params->txt->gun->instances->z = 4;
	if (params->fps % 5 == 0)
	{
		params->gunx = params->gunx + 5;
		params->txt->ground->instances->z = 2;
		params->txt->minimap->instances->z = 3;
	}
}
