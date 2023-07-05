/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/07/05 22:48:36 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

char	**init_params(t_params *p)
{
	int			i;
	int			j;
	parse_error	error;
	char		**lines;

	if (!p->lines)
	{
		ft_putstr_fd("Error\n404 Map Not Found\n", 2);
		cub_free(*p);
	}
	lines = p->lines;
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

char	**get_lines(int fd, t_params *p)
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

parse_error	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'b' && file_name[i - 2] == 'u' && file_name[i
		- 3] == 'c' && file_name[i - 4] == '.')
		return (VALID);
	ft_putstr_fd(error_msgs[INVALID_FILE_EXTENSION], 2);
	return (INVALID_FILE_EXTENSION);
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

parse_error	init_game(t_params *params, int fd)
{
	char	**map;

	params->lines = get_lines(fd, params);
	close(fd);
	map = init_params(params);
	init_map(params, map);
	parse_map(params, map);
	if (init_player(params) != 0)
		return (INVALID);
	print_map(params, NULL);
	if (!params->map->map)
		return (1);
	int **map_copy = (int **)copy_2d_array((void **)params->map->map,
											params->map->map_height,
											params->map->map_width,
											sizeof(int));
	if (check_map(params, params->map->player.map_x, params->map->player.map_y,
			map_copy) != true)
		return (INVALID);
	free_2d_array((void **)map_copy, params->map->map_height);
	return (VALID);
}

int	parse(int argc, char **argv, t_params *params)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr_fd(error_msgs[INVALID_NUM_ARGS], 2);
		cub_free(*params);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd(error_msgs[INVALID_FILE_EXTENSION], 2);
		cub_free(*params);
	}
	if (check_file_name(argv[1]) != VALID)
		cub_free(*params);
	if (init_game(params, fd) != VALID)
	{
		ft_putstr_fd(error_msgs[INIT_GAME_ERROR], 2);
		cub_free(*params);
	}
	return (0);
}