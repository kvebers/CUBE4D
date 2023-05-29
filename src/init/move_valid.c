/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:36:51 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/29 13:42:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

// int	check_cordinates(t_params *params, int x, int y)
// {
// 	if (y <= 0 || x <= 0
// 		|| x >= params->map->total_width
// 		|| y >= params->map->total_height)
// 		return (0);
// 	if ()
// 		return (0);
// 	return (1);
// }


void	check_valid_move(t_params *params, double posx, double posy)
{
	if (params->map->map[(int)(params->map->player.x  + posx)/64][(int)(params->map->player.y + posy) / 64])
	{
		params->map->player.x = params->map->player.x + posx;
		params->map->player.y = params->map->player.y + posy;
	}
}

void	check_valid_move1(t_params *params, double posx, double posy)
{
	if (params->map->map[(int)(params->map->player.x  - posx)/64][(int)(params->map->player.y - posy) / 64])
	{
		params->map->player.x = params->map->player.x - posx;
		params->map->player.y = params->map->player.y - posy;
	}
}
