/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:02:12 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/02 17:20:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

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
}

void	escape(mlx_key_data_t key_data, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(params->mlx);
	if (key_data.key == MLX_KEY_E && key_data.action == MLX_PRESS)
		open_doors(params);
}
