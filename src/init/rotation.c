/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:02:37 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/04 02:13:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "init.h"
#include <math.h>
#include <stdio.h>

void	arrow_pressed_l(t_params *params)
{
	params->map->player.angle = params->map->player.angle - SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}

void	arrow_pressed_r(t_params *params)
{
	params->map->player.angle = params->map->player.angle + SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	mlx_delete_image(params->mlx, params->txt->minimap);
	render_minimap(params);
}
