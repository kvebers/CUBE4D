/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 04:19:44 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:46:53 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_cell(int cell)
{
	return (cell == '1' || cell == '3' || cell == '4' || cell == '9' ||
		cell == '\n' || cell == '\0');
}

bool	check_map(t_params *p, int x, int y, int **map)
{
	bool	is_valid;

	is_valid = true;
	if (!is_valid_cell(map[x][y]))
	{
		if (x < 0 || y < 0 || x == p->map->map_height || map[x][y] == -1)
		{
			ft_putstr_fd("Error\nMap not closed\n", 2);
			return false;
		}

		if (map[x][y] == '0')
			map[x][y] = '3';
		else if (map[x][y] == '2')
			map[x][y] = '4';

		is_valid &= check_map(p, x + 1, y, map);
		is_valid &= check_map(p, x, y + 1, map);
		is_valid &= check_map(p, x - 1, y, map);
		is_valid &= check_map(p, x, y - 1, map);
	}
	return is_valid;
}
