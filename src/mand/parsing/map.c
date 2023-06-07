/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:33 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:36:54 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
				p->map->map[x][y++] = 9;
				j++;
			}
			else if (map[i][j])
				p->map->map[x][y++] = (int)map[i][j++];
		}
		i++;
		x++;
	}
	p->map->map_height = i; /* to change later */
}

int validate_map_input(char **map)
{
	int i = 0;
	int j;
	int emptyline = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			emptyline = 1;
		if (map[i][j] && emptyline)
		{
			ft_putstr_fd("ERROR\nAdditional Input after map\n", 2);
			return 1;
		}
		i++;
	}
	return 0;
}

void calculate_map_dimensions(t_params *p, char **map)
{
	int i = 0;
	int j;
	int len;
	int biglen = 0;

	while (map[i])
	{
		len = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\n' && map[i][j] != '\0')
				len++;
			j++;
		}
		if (len > biglen)
			biglen = len;
		i++;
	}

	p->map->map_height = i;
	p->map->map_width = biglen;
}

void allocate_and_initialize_map(t_params *p, char **map)
{
	int i = 0;

	p->map = (t_map *)malloc(sizeof(t_map));
	p->map->map_height = 0;
	p->map->map_width = 0;
	p->map->map = NULL;

	calculate_map_dimensions(p, map);

	p->map->map = (int **)malloc(p->map->map_height * sizeof(int *));
	i = 0;
	while (i < p->map->map_height)
	{
		p->map->map[i] = (int *)malloc(p->map->map_width * sizeof(int));
		ft_memset(p->map->map[i], 9, p->map->map_width * sizeof(int));
		i++;
	}
}

int init_map(t_params *p, char **map)
{
	if (validate_map_input(map))
		return 1;
	allocate_and_initialize_map(p, map);
	return 0;
}
