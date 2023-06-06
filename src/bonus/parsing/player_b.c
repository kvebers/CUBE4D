/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:54 by asioud            #+#    #+#             */
/*   Updated: 2023/06/06 20:43:35 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	set_angle(t_params *p, char c, int i, int j)
{
	p->map->player.map_x = i;
	p->map->player.map_y = j;
	if (c == 'S')
		p->map->player.angle = 270;
	else if (c == 'W')
		p->map->player.angle = 180;
	else if (c == 'N')
		p->map->player.angle = 90;
	else
		p->map->player.angle = 0;
	return (1);
}

int	init_player(t_params *p)
{
	int	i;
	int	j;
	int	c;
	int	**map;

	i = 0;
	c = 0;
	map = p->map->map;
	while (i < p->map->map_height)
	{
		j = 0;
		while (j < p->map->map_width)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
				c += set_angle(p, map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (c == 0)
		return (ft_putstr_fd("NO SPAWNPOINT\n", 2), 1);
	else if (c > 1)
		return (ft_putstr_fd("MULTIPLE SPAWNPOINTS SET\n", 2), 1);
	return (0);
}
