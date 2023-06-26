/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:12:08 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/26 09:35:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

void	init_enemy_animation1(t_params *params)
{
	params->txt->enemy[10] = mlx_load_png("textures/e/11.png");
	params->txt->enemy[11] = mlx_load_png("textures/e/12.png");
	params->txt->enemy[12] = mlx_load_png("textures/e/13.png");
	params->txt->enemy[13] = mlx_load_png("textures/e/14.png");
	params->txt->enemy[14] = mlx_load_png("textures/e/15.png");
	params->txt->enemy[15] = mlx_load_png("textures/e/16.png");
	params->txt->enemy[16] = mlx_load_png("textures/e/17.png");
	params->txt->enemy[17] = mlx_load_png("textures/e/18.png");
	params->txt->enemy[18] = mlx_load_png("textures/e/19.png");
	params->txt->enemy[19] = mlx_load_png("textures/e/20.png");
	params->txt->enemy[20] = mlx_load_png("textures/e/21.png");
	params->txt->enemy[21] = mlx_load_png("textures/e/22.png");
	params->txt->enemy[22] = mlx_load_png("textures/e/23.png");
	params->txt->enemy[23] = mlx_load_png("textures/e/24.png");
	params->txt->enemy[24] = mlx_load_png("textures/e/25.png");
	params->txt->enemy[25] = mlx_load_png("textures/e/26.png");
}

void	init_enemy_animation(t_params *params)
{
	params->txt->enemy[0] = mlx_load_png("textures/e/1.png");
	params->txt->enemy[1] = mlx_load_png("textures/e/2.png");
	params->txt->enemy[2] = mlx_load_png("textures/e/3.png");
	params->txt->enemy[3] = mlx_load_png("textures/e/4.png");
	params->txt->enemy[4] = mlx_load_png("textures/e/5.png");
	params->txt->enemy[5] = mlx_load_png("textures/e/6.png");
	params->txt->enemy[6] = mlx_load_png("textures/e/7.png");
	params->txt->enemy[7] = mlx_load_png("textures/e/8.png");
	params->txt->enemy[8] = mlx_load_png("textures/e/9.png");
	params->txt->enemy[9] = mlx_load_png("textures/e/10.png");
	init_enemy_animation1(params);
}

void	update_map(t_params *params, int x, int y, int cnt)
{
	int	cnt1;

	while (cnt < params->map->map_height)
	{
		cnt1 = 0;
		while (cnt1 < params->map->map_width)
		{
			if (params->map->map[cnt][cnt1] == '6'
				&& sqrt(pow(cnt - x, 2) + pow(cnt1 - y, 2)) < 2.5)
			{
				params->map->map[cnt][cnt1] = 'a';
				system("afplay ./sound/Swoosh.mp3 &");
			}
			else if (params->map->map[cnt][cnt1] >= 'a'
				&& params->map->map[cnt][cnt1] < 'z')
				params->map->map[cnt][cnt1]++;
			if (params->map->map[cnt][cnt1] == 'z')
			{
				mlx_close_window(params->mlx);
				params->lose = 1;
			}
			cnt1++;
		}
		cnt++;
	}
}
