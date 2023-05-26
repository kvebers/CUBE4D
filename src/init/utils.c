/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:37:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/26 15:07:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

uint32_t	rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	count_lines(char **lines)
{
	int	cnt;

	cnt = 7;
	while (lines[cnt] != NULL)
		cnt++;
	return (cnt);
}

int	get_longest_line(char **lines)
{
	size_t	temp;
	int		cnt;

	temp = 0;
	cnt = 7;
	while (lines[cnt] != NULL)
	{
		if (ft_strlen(lines[cnt]) > temp)
			temp = ft_strlen(lines[cnt]);
		cnt++;
	}
	return ((int) temp);
}

void	get_player_pos(t_params *params)
{
	int	cnt;
	int	cnt1;

	cnt = 7;
	cnt1 = 0;
	while (params->lines[cnt] != NULL)
	{
		if (ft_strchr(params->lines[cnt], 'N') != NULL)
		{
			params->map->player.y = cnt * 64 + 32;
			while (*(params->lines[cnt] + cnt1) != 'N')
				cnt1++;
			params->map->player.x = cnt1 * 64 + 32;
			break ;
		}
		cnt++;
	}
}
