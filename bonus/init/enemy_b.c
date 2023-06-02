/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:22:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/02 18:55:26 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	spawn_duck(t_params *params, int x, int y)
{
	if (sqrt(pow(params->map->player.x - x * 64, 2)
			+ pow(params->map->player.x - x * 64, 2)) < 500)
		return ;
	params->duck.alive = 1;
	params->duck.speed = 1;
	params->duck.x = x * 64;
	params->duck.y = y * 64 + 42;
}

void	spawn_bob(t_params *params, int x, int y)
{
	if (sqrt(pow(params->map->player.x - x * 64, 2)
			+ pow(params->map->player.x - x * 64, 2)) < 500)
		return ;
	params->bob.alive = 1;
	params->bob.speed = 1;
	params->bob.x = x * 64;
	params->bob.y = y * 64 + 42;
}

