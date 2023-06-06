/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:37:56 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

void	w_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	s_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			- 180);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	a_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			- 90);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	d_pressed(t_params *params)
{
	t_vector	vector;

	vector = vector_estimation(params->map->speed, params->map->player.angle
			+ 90);
	check_valid_move1(params, vector.pos_x, vector.pos_y);
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	keyhook(mlx_key_data_t key_data, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(params->mlx);
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
		w_pressed(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_S))
		s_pressed(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
		arrow_pressed_l(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
		arrow_pressed_r(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_A))
		a_pressed(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_D))
		d_pressed(params);
}
