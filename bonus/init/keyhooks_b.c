/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/20 11:11:22 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	w_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
}

void	s_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			- 180);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
}

void	a_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			- 90);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
}

void	d_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			+ 90);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
}

void	keyhook(void *param)
{
	t_params		*params;

	params = (t_params *)param;
	params->fps++;
	check_sound();
	if (params->pause == 1)
		return ;
	gun_stuff(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
		w_pressed(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_S))
		s_pressed(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_A))
		a_pressed(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_D))
		d_pressed(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
		arrow_pressed_l(params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
		arrow_pressed_r(params);
	mousehook(params);
	update_map(params);
	do_the_rendering(params);
}

