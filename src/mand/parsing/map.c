/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:33 by asioud            #+#    #+#             */
/*   Updated: 2023/07/08 00:28:13 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	convert_values(int x, int y, int **map)
{
	if (map[x][y] == '0')
		map[x][y] = '3';
	if (map[x][y] == '2')
		map[x][y] = '4';
}

bool	is_outer(int x, int y, t_params *p)
{
	return (x == 0 || y == 0 || x == p->map->map_height - 1 \
		|| y == p->map->map_width - 1);
}

bool	check_map(t_params *p, int x, int y, int **map)
{
	if (map[x][y] == '1')
		return (is_outer(x, y, p));
	if (map[x][y] == '3' || map[x][y] == '4' \
		|| map[x][y] == '\n' || map[x][y] == '\0')
		return (true);
	if (x < 0 || y < 0 || x >= p->map->map_height \
		|| y >= p->map->map_width || map[x][y] == -1)
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		cub_free(*p);
	}
	if (is_outer(x, y, p))
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		cub_free(*p);
	}
	convert_values(x, y, map);
	return (check_map(p, x + 1, y, map) \
		&& check_map(p, x, y + 1, map) \
		&& check_map(p, x - 1, y, map) \
		&& check_map(p, x, y - 1, map));
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
				p->map->map[x][y++] = '9';
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
