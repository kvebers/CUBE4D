/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:02:12 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mousehook(t_params *params)
{
	int32_t		x;
	int32_t		y;

	x = params->map->size_x / 2;
	y = 0;
	mlx_set_cursor_mode(params->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(params->mlx, &x, &y);
	mlx_set_mouse_pos(params->mlx, params->map->size_x / 2,
		params->map->size_y / 2);
	if (x > (int32_t) params->map->size_x / 2 + 60)
		arrow_pressed_r(params);
	else if (x < (int32_t) params->map->size_x / 2 - 60)
		arrow_pressed_l(params);
	if (mlx_is_mouse_down(params->mlx, MLX_MOUSE_BUTTON_LEFT)
		&& params->gun_state == 0)
		params->gun_state = 4;
}

void	render_pause(t_params *params)
{
	render_skybox(params);
	render_map(params);
	render_minimap(params);
	render_gun(params);
	mlx_delete_image(params->mlx, params->txt->pause_i);
	params->pause = 2;
}

void	escape(mlx_key_data_t key_data, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(params->mlx);
	if (key_data.key == MLX_KEY_E && key_data.action == MLX_PRESS
		&& params->pause != 1)
		open_doors(params);
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS
		&& params->pause == 1)
		render_pause(params);
	if (key_data.key == MLX_KEY_UP
		&& key_data.action == MLX_PRESS && params->gun_state == 0)
		params->gun_state = 4;
}

void	do_the_rendering(t_params *params)
{
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
