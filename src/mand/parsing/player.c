/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:54 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 13:50:19 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_angle(t_params *p, char c)
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

void	print_err(int c, t_params *p)
{
	if (c == 0)
	{
		ft_putstr_fd("NO SPAWNPOINT\n", 2);
		cub_free(*p);
	}
	else if (c > 1)
	{
		ft_putstr_fd("MULTIPLE SPAWNPOINTS SET\n", 2);
		cub_free(*p);
	}
}

void	init_init_player(int *c, int *i, int ***map, t_params *p)
{
	*c = 0;
	*i = 0;
	*map = p->map->map;
}

int	init_player(t_params *p)
{
	int	i;
	int	j;
	int	c;
	int	**map;

	init_init_player(&c, &i, &map, p);
	while (i < p->map->map_height)
	{
		j = 0;
		while (j < p->map->map_width)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
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
	print_err(c, p);
	return (0);
}
