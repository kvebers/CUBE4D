/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	update_map(params, params->map->player.x / 64,
		params->map->player.y / 64, 0);
	do_the_rendering(params);
}
