/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:54 by asioud            #+#    #+#             */
/*   Updated: 2023/05/27 16:05:02 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


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
	while (i < p->map->size_x)
	{
		j = 0;
		while (j < p->map->size_y)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
			|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				p->map->player.x = i;
				p->map->player.y = j;
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

