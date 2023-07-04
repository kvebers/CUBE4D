/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:36:51 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 15:49:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_move1(t_params *params, double posx, double posy)
{
	int	x;
	int	y;

	x = (int)((round(params->map->player.x + posx * 1.5) / 64));
	y = (int)((round(params->map->player.y + posy * 1.5) / 64));
	if (params->map->map[x][y] != '1')
	{
		params->map->player.x = params->map->player.x + posx;
		params->map->player.y = params->map->player.y + posy;
	}
}
