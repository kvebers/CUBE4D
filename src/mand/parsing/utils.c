/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 04:18:22 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:51:46 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_params *p, char **map)
{
	int	i;
	int	j;

	printf("\n");
	i = 0;
	j = 0;
	while (i < p->map->map_height)
	{
		j = 0;
		while (j < p->map->map_width)
		{
			put_chars((char)p->map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	(void)map;
}

char	put_chars(char c)
{
	char colored_0[] = "\e[1;37m0\e[0m";
	char colored_1[] = "\e[1;31m1\e[0m";
	char colored_e[] = "\e[1;32mE\e[0m";
	char colored_s[] = "\e[1;32mS\e[0m";
	char colored_w[] = "\e[1;35mW\e[0m";
	char colored_n[] = "\e[1;34mN\e[0m";
	char colored_x[] = "\e[1;34mX\e[0m";
	char colored_plus[] = "\e[1;34m+\e[0m";
	char colored_9[] = "\e[1;33m9\e[0m";

	if (c == '0')
		write(1, &colored_0, 13);
	else if (c == '1')
		write(1, &colored_1, 13);
	else if (c == 'N')
		write(1, &colored_n, 13);
	else if (c == 'S')
		write(1, &colored_s, 13);
	else if (c == 'W')
		write(1, &colored_w, 13);
	else if (c == 'E')
		write(1, &colored_e, 13);
	else if (c == '+')
		write(1, &colored_plus, 13);
	else if (c == 9)
		write(1, &colored_9, 13);
	else if (c == 'X')
		write(1, &colored_x, 13);
	else if (c == ' ')
		write(1, " ", 1);
	return (0);
}

char	**get_lines(int fd)
{
	char	**lines;
	char	**tmp;
	char	*s;
	int		i;
	int		j;

	lines = NULL;
	tmp = NULL;
	i = 1;
	s = get_next_line(fd);
	while (s)
	{
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		if (tmp)
			while (tmp[j])
			{
				lines[j] = tmp[j];
				j++;
			}
		lines[j++] = s;
		lines[j] = 0;
		i++;
		s = get_next_line(fd);
		free(tmp);
	}
	free(s);
	return (lines);
}

void	debug_info(t_params *params)
{
	printf("--------------------- debug info ---------------------\n");
	printf("map: %p\n", (void *)params->map);
	printf("mlx: %p\n", (void *)params->mlx);
	printf("floor: %s    | r:%d g:%d b:%d\n", params->floor ? "true" : "false",
			params->txt->f_r, params->txt->f_g, params->txt->f_b);
	printf("ceiling: %s  | r:%d g:%d b:%d\n",
			params->ceiling ? "true" : "false",
			params->txt->c_r,
			params->txt->c_g,
			params->txt->c_b);
	printf("north: %s  | %p\n", params->north ? "true" : "false",
			params->txt->no);
	printf("south: %s  | %p\n", params->south ? "true" : "false",
			params->txt->so);
	printf("west: %s   | %p\n", params->west ? "true" : "false",
			params->txt->we);
	printf("east: %s   | %p\n", params->east ? "true" : "false",
			params->txt->ea);
	printf("player_pos_x: %f\nplayer_pos_y: %f\n", params->map->player.map_x,
			params->map->player.map_y);
	printf("player_angle: %f\n", params->map->player.angle);
	printf("player_speed: %d\n", params->map->speed);
	printf("minimap_box: %d\n", params->map->minimap_box);
	printf("offset: %d\n", params->map->offset);
	printf("map_size_x: %d\nmap_size_y: %d\n",
			params->map->size_x,
			params->map->size_y);
	printf("height: %d\n", params->map->map_height);
	printf("width: %d\n", params->map->map_width);
	printf("total_height: %d\n", params->map->total_height);
	printf("total_width: %d\n", params->map->total_width);
	printf("---------------------- fin info ----------------------\n");
}

