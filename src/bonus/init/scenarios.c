/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:06:03 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	trigger_scenarios(t_params *params)
{
	t_vector	vector;

	srand(time(0));
	vector = vector_estimation(64, params->map->player.angle);
	if (rand() % 4 == 0)
		params->global_light = 40;
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
