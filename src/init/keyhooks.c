/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/26 15:17:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	a_pressed(t_params *params)
{
	params->map->player.angle++;
	if (params->map->player.angle > 360)
		params->map->player.angle = params->map->player.angle - 360;
	mlx_delete_image(params->mlx, params->txt->minimap);
	printf("%i\n", params->map->player.angle);
	render_minimap(params);
}

void	d_pressed(t_params *params)
{
	params->map->player.angle--;
	if (params->map->player.angle < 0)
		params->map->player.angle = 360 + params->map->player.angle;
	printf("%i\n", params->map->player.angle);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	w_pressed(t_params *params)
{
	if (*(params->lines[(int)(params->map->player.y - params->map->speed) / 64]
			+ (int) params->map->player.x / 64) != '1')
	{
		params->map->player.y = params->map->player.y - params->map->speed;
		mlx_delete_image(params->mlx, params->txt->minimap);
		render_minimap(params);
	}
}

void	s_pressed(t_params *params)
{
	
	if (*(params->lines[((int)(params->map->player.y + params->map->speed)) / 64]
			+ (int) params->map->player.x / 64) != '1')
	{
		params->map->player.y = params->map->player.y + params->map->speed;
		mlx_delete_image(params->mlx, params->txt->minimap);
		render_minimap(params);
	}
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
	else if (mlx_is_key_down(params->mlx, MLX_KEY_A))
		a_pressed(params);
	else if (mlx_is_key_down(params->mlx, MLX_KEY_D))
		d_pressed(params);
}
