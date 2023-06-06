/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:48:20 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	params->guny = params->guny - 5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
	params->txt->gun->instances->z = 4;
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
	params->guny = params->guny + 5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
	params->txt->gun->instances->z = 4;
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
	params->gunx = params->gunx - 5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
	params->txt->gun->instances->z = 4;
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
	params->gunx = params->gunx + 5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
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
}

