/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_valid_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:36:51 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/26 10:09:41 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	check_valid_move1(t_params *params, double posx, double posy)
{
	int	x;
	int	y;

	x = (int)((round(params->map->player.x + posx * 1.5) / 64));
	y = (int)((round(params->map->player.y + posy * 1.5) / 64));
	if (params->map->map[x][y] != '1'
		&& params->map->map[x][y] != '2'
		&& params->map->map[x][y] != '3'
		&& params->map->map[x][y] != '6'
		&& params->map->map[x][y] < 'a')
	{
		params->map->player.x = params->map->player.x + posx;
		params->map->player.y = params->map->player.y + posy;
		if (params->map->map[x][y] == '5')
			trigger_scenarios(params);
	}
}
