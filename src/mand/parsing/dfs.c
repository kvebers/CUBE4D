/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 04:19:44 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:19:53 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_map(t_params *p, int x, int y, int **map)
{
	bool	is_valid;

	if (map[x][y] == '1' || map[x][y] == '3' || map[x][y] == '4')
		return (true);
	if (map[x][y] == '9')
		return (true);
	if (map[x][y] == '\n' || map[x][y] == '\0')
		return (true);
	if ((x < 0 || y < 0 || x == p->map->map_height))
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		return (false);
	}
	if (map[x][y] == -1)
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		return (false);
	}
	if (map[x][y] == '0')
		map[x][y] = '3';
	if (map[x][y] == '2')
		map[x][y] = '4';
	is_valid = true;
	is_valid &= check_map(p, x + 1, y, map);
	is_valid &= check_map(p, x, y + 1, map);
	is_valid &= check_map(p, x - 1, y, map);
	is_valid &= check_map(p, x, y - 1, map);
	return (is_valid);
}
