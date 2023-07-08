/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:33 by asioud            #+#    #+#             */
/*   Updated: 2023/07/08 04:51:13 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_map(t_params *p, int x, int y, int **map)
{
	bool	is_valid;

	if (x >= p->map->map_height || y >= p->map->map_width || x < 0 || y < 0)
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		cub_free(*p);
	}
	if (map[x][y] == '1' || map[x][y] == 'x')
		return (true);
	map[x][y] = 'x';
	is_valid = true;
	is_valid &= check_map(p, x + 1, y, map);
	is_valid &= check_map(p, x, y + 1, map);
	is_valid &= check_map(p, x - 1, y, map);
	is_valid &= check_map(p, x, y - 1, map);
	is_valid &= check_map(p, x + 1, y + 1, map);
	is_valid &= check_map(p, x + 1, y - 1, map);
	is_valid &= check_map(p, x - 1, y + 1, map);
	is_valid &= check_map(p, x - 1, y - 1, map);
	return (is_valid);
}

void	parse_map(t_params *p, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	i = 0;
	while (map[i])
	{
		y = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\n')
			{
				p->map->map[x][y++] = 1;
				j++;
			}
			else if (map[i][j])
				p->map->map[x][y++] = (int)map[i][j++];
		}
		i++;
		x++;
	}
	p->map->map_height = i;
}

void	init_map(t_params *p, char **map)
{
	check_empty_line(p, map);
	compute_map_width(p, map);
	allocate_map(p);
}
