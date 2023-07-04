/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:54 by asioud            #+#    #+#             */
/*   Updated: 2023/06/01 16:39:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"


static void set_angle(t_params *p, char c)
{
	if (c == 'S')
		p->map->player.angle = 270;
	else if (c == 'W')
		p->map->player.angle = 180;
	else if (c == 'N')
		p->map->player.angle = 90;
	else
		p->map->player.angle = 0;
}

/**
 * @brief loop through the map to find the player's spawn point
 * and counts the number of players in the map (should be 1) 
 * 
 * @param p The params struct
 * @return 0 if only one player is found with valid direction,
 * 		1 otherwise
 */
int	init_player(t_params *p)
{
	int	i;
	int	j;
	int c;
	int **map;

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
			{
				p->map->player.map_x = i;
				p->map->player.map_y = j;
				set_angle(p, map[i][j]);
				c++;
			}
			j++;
		}
		i++;
	}
	if (c == 0)
	{
		ft_putstr_fd("NO SPAWNPOINT\n", 2);
		return 1;
	}
	else if (c > 1)
	{
		ft_putstr_fd("MULTIPLE SPAWNPOINTS SET\n", 2);
		return 1;
	}
	return 0;
	
}
