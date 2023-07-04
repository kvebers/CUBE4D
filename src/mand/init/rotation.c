/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:02:37 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 15:49:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	arrow_pressed_l(t_params *params)
{
	params->map->player.angle = params->map->player.angle - SPEED / 2;
}

void	arrow_pressed_r(t_params *params)
{
	params->map->player.angle = params->map->player.angle + SPEED / 2;
}
