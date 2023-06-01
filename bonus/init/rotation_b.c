/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:02:37 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/01 18:55:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include <math.h>

void	arrow_pressed_l(t_params *params)
{
	params->map->player.angle = params->map->player.angle - SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	params->txt->ground->instances->z = 1;
	params->txt->minimap->instances->z = 2;
}

void	arrow_pressed_r(t_params *params)
{
	params->map->player.angle = params->map->player.angle + SPEED / 2;
	mlx_delete_image(params->mlx, params->txt->ground);
	render_skybox(params);
	render_map(params);
	params->txt->ground->instances->z = 1;
	params->txt->minimap->instances->z = 2;
}
