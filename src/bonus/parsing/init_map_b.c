/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:14:51 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 15:07:32 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_empty_line(t_params *p, char **map)
{
	int	i;
	int	j;
	int	emptyline;

	i = 0;
	emptyline = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			emptyline = 1;
		if (map[i][j] && emptyline)
			ft_putstr_fd("ERROR\nAdditional Input after map\n", 2);
		i++;
	}
	p->map = (t_map *)my_malloc(&p->mem, sizeof(t_map));
	p->map->map_height = i;
}

void	compute_map_width(t_params *p, char **map)
{
	int	i;
	int	j;
	int	len;
	int	biglen;

	i = 0;
	j = 0;
	len = 0;
	biglen = 0;
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
	p->map->map_width = biglen;
}

void	allocate_map(t_params *p)
{
	int	i;

	p->map->map = (int **)my_malloc \
	(&p->mem, p->map->map_height * sizeof(int *));
	i = 0;
	while (i < p->map->map_height)
	{
		p->map->map[i] = (int *)my_malloc \
		(&p->mem, p->map->map_width * sizeof(int));
		ft_memset(p->map->map[i], 9, p->map->map_width * sizeof(int));
		i++;
	}
}
