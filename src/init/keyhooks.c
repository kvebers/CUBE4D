/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:02:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/26 00:04:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	keyhook(mlx_key_data_t key_data, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(params->mlx);
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
	{
		if (*(params->lines[(params->map->player.y - 4) /64] + params->map->player.x / 64) != '1')
		{
			params->map->player.y = params->map->player.y - 4;
			mlx_delete_image(params->mlx, params->txt->minimap);
			render_minimap(params);
		}
	}
	else if (mlx_is_key_down(params->mlx, MLX_KEY_S))
	{
		if (*(params->lines[(params->map->player.y + 4) /64] + params->map->player.x / 64) != '1')
		{
			params->map->player.y = params->map->player.y + 4;
			mlx_delete_image(params->mlx, params->txt->minimap);
			render_minimap(params);
		}
	}
}
