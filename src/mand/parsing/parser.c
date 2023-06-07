/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:23:32 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	init_params(t_params *p, char ***map)
{
	int			i;
	int			j;
	char		**lines;

	lines = p->lines;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (set_params(lines[i][j], lines[i], p) != VALID)
		{
			*map = &lines[i];
			return (VALID);
		}
		i++;
	}
	ft_putstr_fd("Error\nMap not found\n", 2);
	return (INVALID);
}

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'b' && file_name[i - 2] == 'u' && file_name[i
		- 3] == 'c' && file_name[i - 4] == '.')
		return (VALID);
	ft_putstr_fd("Error\nInvalid file extension\n", 2);
	return (INVALID);
}

int	init_game(t_params *params, int fd) {
	char	**map;

	map = NULL;
	params->lines = get_lines(fd);
	close(fd);
	if (init_params(params, &map) != VALID)
		return (INVALID);
	if (init_map(params, map))
		return (INVALID);
	parse_map(params, map);
	init_player(params);
	
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
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		return (1);
	}
	if (check_file_name(argv[1]) != VALID)
	{
		return (1);
	}
	if (init_game(params, fd) != VALID)
	{
		ft_putstr_fd("Error\nGame initialization failed\n", 2);
		return (1);
	}

	return (0);
}