/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:02:37 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:49:45 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	arrow_pressed_l(t_params *params)
{
	params->map->player.angle = params->map->player.angle - SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	params->gunx = -5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
	params->txt->gun->instances->z = 4;
}

void	arrow_pressed_r(t_params *params)
{
	params->map->player.angle = params->map->player.angle + SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	params->gunx = params->gunx + 5;
	params->txt->ground->instances->z = 2;
	params->txt->minimap->instances->z = 3;
	params->txt->gun->instances->z = 4;
}