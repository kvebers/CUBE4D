/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:44:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/06 15:30:26 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_textures(t_params *params)
{
	int	cnt;

	cnt = 0;
	mlx_delete_image(params->mlx, params->txt->pause_i);
	mlx_delete_image(params->mlx, params->txt->gun);
	mlx_delete_image(params->mlx, params->txt->minimap);
	mlx_delete_image(params->mlx, params->txt->ground);
	mlx_delete_texture(params->txt->gun0);
	mlx_delete_texture(params->txt->gun1);
	mlx_delete_texture(params->txt->gun2);
	mlx_delete_texture(params->txt->gun3);
	mlx_delete_texture(params->txt->pause_t);
	mlx_delete_texture(params->txt->static_enemy1);
	mlx_delete_texture(params->txt->static_enemy2);
	mlx_delete_texture(params->map->def);
	mlx_delete_texture(params->map->door);
	while (cnt < 26)
	{
		mlx_delete_texture(params->txt->enemy[cnt]);
		cnt++;
	}
}
