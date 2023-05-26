/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:36:51 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/26 19:41:44 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

void	check_valid_move(t_params *params, float posx, float posy)
{
	if (*(params->lines[((int)(params->map->player.y + posy))
			/ 64] + (int) params->map->player.x / 64) != '1')
	{
		if (*(params->lines[((int)(params->map->player.y))
				/ 64] + (int)(params->map->player.x / 64 + posx /64)) != '1')
		{
			params->map->player.x = params->map->player.x + posx;
			params->map->player.y = params->map->player.y + posy;
		}
	}
}

void	check_valid_move1(t_params *params, float posx, float posy)
{
	if (*(params->lines[((int)(params->map->player.y - posy))
			/ 64] + (int) params->map->player.x / 64) != '1')
	{
		if (*(params->lines[((int)(params->map->player.y))
				/ 64] + (int)(params->map->player.x / 64 - posx / 64)) != '1')
		{
			params->map->player.x = params->map->player.x - posx;
			params->map->player.y = params->map->player.y - posy;
		}
	}
}