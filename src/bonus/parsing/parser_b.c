/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/07/08 00:40:55 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**init_params(t_params *p)
{
	int				i;
	int				j;
	char			**lines;

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
		if (set_params(lines[i][j], lines[i], p) != 0)
			return (&lines[i]);
		i++;
	}
	ft_putstr_fd("Error\nMap not found\n", 2);
	return (NULL);
}

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'b' && file_name[i - 2] == 'u' \
	&& file_name[i - 3] == 'c' && file_name[i - 4] == '.')
		return (0);
	return (1);
}

int	init_game(t_params *params, int fd)
{
	char	**map;
	int		**map_copy;

	params->lines = get_lines(fd, params);
	close(fd);
	map = init_params(params);
	init_map(params, map);
	parse_map(params, map);
	if (init_player(params) != 0)
		return (1);
	if (!params->map->map)
		return (1);
	map_copy = (int **)copy_2d_array((void **)params->map->map,
			params->map->map_height,
			params->map->map_width,
			sizeof(int));
	if (check_map(params, params->map->player.map_x, params->map->player.map_y,
			map_copy) != true)
		return (1);
	free_2d_array((void **)map_copy, params->map->map_height);
	return (0);
}

int	parse(int argc, char **argv, t_params *params)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		cub_free(*params);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		cub_free(*params);
	}
	if (check_file_name(argv[1]) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		cub_free(*params);
	}
	if (init_game(params, fd) != 0)
	{
		ft_putstr_fd("Error\nGame initialization failed\n", 2);
		cub_free(*params);
	}
	return (0);
}

// void debug_info(t_params *params)
// {
// 	printf("--------------------- debug info ---------------------\n");
// 	printf("map: %p\n", (void *)params->map);
// 	printf("mlx: %p\n", (void *)params->mlx);
// 	printf("floor: %s    | r:%d g:%d b:%d\n", params->floor ? "true" : "false",
// 		   params->txt->f_r, params->txt->f_g, params->txt->f_b);
// 	printf("ceiling: %s  | r:%d g:%d b:%d\n",
// 		   params->ceiling ? "true" : "false",
// 		   params->txt->c_r,
// 		   params->txt->c_g,
// 		   params->txt->c_b);
// 	printf("north: %s  | %p\n", params->north ? "true" : "false",
// 		   params->txt->no);
// 	printf("south: %s  | %p\n", params->south ? "true" : "false",
// 		   params->txt->so);
// 	printf("west: %s   | %p\n", params->west ? "true" : "false",
// 		   params->txt->we);
// 	printf("east: %s   | %p\n", params->east ? "true" : "false",
// 		   params->txt->ea);
// 	printf("player_pos_x: %f\nplayer_pos_y: %f\n", params->map->player.map_x,
// 		   params->map->player.map_y);
// 	printf("player_angle: %f\n", params->map->player.angle);
// 	printf("player_speed: %d\n", params->map->speed);
// 	printf("minimap_box: %d\n", params->map->minimap_box);
// 	printf("offset: %d\n", params->map->offset);
// 	printf("map_size_x: %d\nmap_size_y: %d\n",
// 		   params->map->size_x,
// 		   params->map->size_y);
// 	printf("height: %d\n", params->map->map_height);
// 	printf("width: %d\n", params->map->map_width);
// 	printf("total_height: %d\n", params->map->total_height);
// 	printf("total_width: %d\n", params->map->total_width);
// 	printf("---------------------- fin info ----------------------\n");
// }
