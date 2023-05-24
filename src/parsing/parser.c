/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/05/24 08:40:25 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../cub3d.h"

parse_error		set_params(char c, char *str, t_params *p)
{
	while (*str == ' ')
		str++;

	if (c == 'F' && *(str + 1) == ' ')
	{
		if (p->floor)
			return (MULT_NORTH_INPUT);
		else
			set_floor(str, p);
	}
	else if (c == 'C' && *(str + 1) == ' ')
	{
		if (p->ceiling)
			return (MULT_SOUTH_INPUT);
		else
			set_ceiling(str, p);
	}
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
	{
		if (p->north)
			return (MULT_NORTH_INPUT);
		else
		{
			p->north = true;
			if (open(str, O_RDONLY) == -1)
				return (INVALID_NORTH_PATH);
			else
				p->txt->no = mlx_load_png(str);
		}
	}
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
	{
		if (p->south)
			return (MULT_SOUTH_INPUT);
		else
		{
			p->south = true;
			printf("south");	
			if (open(str, O_RDONLY) == -1)
				return (INVALID_SOUTH_PATH);
			else
				p->txt->so = mlx_load_png(str);
		}
	}
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
	{
		if (p->west)
			return (MULT_WEST_INPUT);
		else
		{
			p->west = true;
			if (open(str, O_RDONLY) == -1)
				return (INVALID_WEST_PATH);
			else
				p->txt->we = mlx_load_png(str);
		}
	}
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
	{
		if (p->east)
			return (MULT_NORTH_INPUT);
		else
		{
			p->east = true;
			if (open(str, O_RDONLY) == -1)
				return (INVALID_EAST_PATH);
			else
				p->txt->ea = mlx_load_png(str);
		}
	}
	else if (c)
		return (INVALID_IDENTIFIERS);
	return (VALID);
}

char	**init_params(t_params *p)
{
	int i;
	int j;
	int map;
	char **lines = p->lines;

	i = 0;
	map = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!set_params(lines[i][j], lines[i], p))
			return (&lines[i]);
		i++;
	}
	ft_putstr_fd("ERROR\nNO MAP FOUND\n", 2);
	return (lines);
}

char	**get_lines(int fd)
{
	char	**lines = 0;
	char	**tmp = NULL;
	char	*s;
	int		i;
	int		j;

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
	}
	return (lines);
}

static void printParams(t_params *params) {
    printf("\nlines: %p\n", (void *)params->lines);
    printf("txt: %p\n", (void *)params->txt);
    printf("map: %p\n", (void *)params->map);
    printf("mlx: %p\n", (void *)params->mlx);
    printf("floor: %s\n", params->floor ? "true" : "false");
    printf("ceiling: %s\n", params->ceiling ? "true" : "false");
    printf("north: %s\n", params->north ? "true" : "false");
    printf("south: %s\n", params->south ? "true" : "false");
    printf("west: %s\n", params->west ? "true" : "false");
    printf("east: %s\n", params->east ? "true" : "false");
}

parse_error parse(int argc, char **argv, t_params *params)
{
	int		fd;
	int		i = 0;

	if (argc > 3 || argc < 2)
		return (INVALID_NUM_ARGS);

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (INVALID_FILE);

	params->lines = get_lines(fd);
	close(fd);
	
	while (params->lines[i])
		printf("%s", params->lines[i++]);


	char **map = init_params(params);
	
	printf("\n\nmap: %s\n", map[0]);
	
	printParams(params);
	
	
	
	return (VALID);
}