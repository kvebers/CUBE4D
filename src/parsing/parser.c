/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/05/27 16:42:21 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../cub3d.h"


parse_error		set_params(char c, char *str, t_params *p)
{
	char *path;
	parse_error err;

	path = ft_strtrim(str+3, "\n");
	while (*str == ' ')
		str++;
	
	if (c == 'F' && *(str + 1) == ' ')
	{
		if (p->floor)
			return (MULT_NORTH_INPUT);
		else
			if ((err = set_floor(str, p)) != VALID)
				ft_putstr_fd(error_msgs[INVALID_FLOOR_FORMAT], 2);
	}
	else if (c == 'C' && *(str + 1) == ' ')
	{
		if (p->ceiling)
			return (MULT_SOUTH_INPUT);
		else
			if ((err = set_ceiling(str, p)) != VALID)
				ft_putstr_fd(error_msgs[INVALID_FLOOR_FORMAT], 2);
	}
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
	{
		if (p->north)
			return (MULT_NORTH_INPUT);
		else
		{
			if (open(path, O_RDONLY) == -1)
			{
				ft_putstr_fd(error_msgs[INVALID_NORTH_PATH], 2);
				return (INVALID_NORTH_PATH);
			}
			else
				p->txt->no = mlx_load_png(path);
			p->north = true;
		}
	}
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
	{
		if (p->south)
			return (MULT_SOUTH_INPUT);
		else
		{
			if (open(path, O_RDONLY) == -1)
			{
				ft_putstr_fd(error_msgs[INVALID_SOUTH_PATH], 2);
				return (INVALID_SOUTH_PATH);
			}
			else
				p->txt->so = mlx_load_png(path);
			p->south = true;
		}
	}
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
	{
		if (p->west)
			return (MULT_WEST_INPUT);
		else
		{
			if (open(path, O_RDONLY) == -1)
			{
				ft_putstr_fd(error_msgs[INVALID_WEST_PATH], 2);
				return (INVALID_WEST_PATH);
			}
			else
				p->txt->we = mlx_load_png(path);
			p->west = true;
		}
	}
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
	{
		if (p->east)
			return (MULT_NORTH_INPUT);
		else
		{
			if (open(path, O_RDONLY) == -1)
			{
				ft_putstr_fd(error_msgs[INVALID_EAST_PATH], 2);
				return (INVALID_EAST_PATH);
			}
			else
				p->txt->ea = mlx_load_png(path);
			p->east = true;
		}
	}
	else if (c == '1' || c == '2' || c == '0')
		return (INVALID_IDENTIFIERS);
	return (VALID);
}

/**
 * @brief Parse the map file and set the parameters 
 * @param p pointer to the params struct
 * @return char** pointer to the first line of the map 
 */
char	**init_params(t_params *p)
{
	int i;
	int j;
	char **lines = p->lines;
	parse_error error;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		error = set_params(lines[i][j], lines[i], p);
		if (error != VALID)
			return (&lines[i]);
		i++;
	}
	ft_putstr_fd(error_msgs[MAP_404], 2);
	return (NULL);
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

void debug_info(t_params *params) 
{
	printf("--------------------- debug info ---------------------\n");
    printf("lines: %p\n", (void *)params->lines);
    printf("txt: %d %d %d\n", params->txt->c_r, params->txt->c_g, params->txt->c_b);
    printf("txt: %d %d %d\n", params->txt->f_r, params->txt->f_g, params->txt->f_b);
    printf("map: %p\n", (void *)params->map);
    printf("mlx: %p\n", (void *)params->mlx);
    printf("floor: %s\n", params->floor ? "true" : "false");
    printf("ceiling: %s\n", params->ceiling ? "true" : "false");
    printf("north: %s\n", params->north ? "true" : "false");
    printf("south: %s\n", params->south ? "true" : "false");
    printf("west: %s\n", params->west ? "true" : "false");
    printf("east: %s\n", params->east ? "true" : "false");
	printf("map_size_x: %d\nmap_size_y: %d\n", params->map->size_x, params->map->size_y);
	printf("player_pos_x: %d\nplayer_pos_y: %d\n", params->map->player.x, params->map->player.y);
	printf("---------------------- fin info ----------------------\n");
}

int parse(int argc, char **argv, t_params *params)
{
	int		fd;
	params->txt = malloc(sizeof(t_textures));
	if (argc != 3)
	{
		ft_printf_fd(2, error_msgs[INVALID_NUM_ARGS]);
		return (1);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_printf_fd(2, error_msgs[INVALID_FILE]);
		return (1);
	}

	params->lines = get_lines(fd);
	close(fd);

	char **map = init_params(params);
	init_map(params, map);
	parse_map(params, map);
	print_map(params, map);
	init_player(params);
	debug_info(params);

	if (!params->map->map)
		return 1;

	check_map(params, params->map->player.x, params->map->player.y);
	return (0);
}