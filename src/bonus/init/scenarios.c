/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:06:03 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/03 19:46:15 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>


void	trigger_duck(t_params *params)
{
	(void) params;
}

void	trigger_scenarios(t_params *params)
{
	t_vector	vector;

	srand(time(0));
	vector = vector_estimation(64, params->map->player.angle);
	if (rand() % 4 == 0)
	{
		params->global_light = 255;
		trigger_duck(params);
		params->global_light = 40;
	}
	else if (rand() % 4 == 2)
	{
		params->global_light += 5;
		system("afplay ./sound/sound.mp3 &");
	}
	else if (rand() % 4 == 1)
		system("afplay ./sound/ok.mp3 &");
	params->map->map[(int)params->map->player.x
		/ 64][(int)params->map->player.y / 64] = '0';
}
