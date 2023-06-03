/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/06/03 19:35:19 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../cub3d.h"

void free_2d_array(void **array, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief Parse the map(p->lines) and set the parameters 
 * @param p pointer to the params struct
 * @return char** pointer to the first line of the map 
 */
char	**init_params(t_params *p)
{
	int			i;
	int			j;
	parse_error	error;
	char **lines;
	
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

/**
 * @brief get all lines from files and store them in a char**
 * @param fd the file descriptor
 * @return char** which represents the whole file
 */
char	**get_lines(int fd)
{
	char	**lines = NULL;
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

/**
 * @brief check if the file name ends with .cub
 * @param file_name the name of the file
 * @return parse_error INVALID_FILE_EXTENSION if the file extension is not .cub
 */
parse_error check_file_name(char *file_name)
{
	int i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'b' && file_name[i - 2] == 'u' \
		&& file_name[i - 3] == 'c' && file_name[i - 4] == '.')
		return (VALID);
	ft_printf_fd(2, error_msgs[INVALID_FILE_EXTENSION]);
	return (INVALID_FILE_EXTENSION);
}

void debug_info(t_params *params) 
{
	printf("--------------------- debug info ---------------------\n");
		
    printf("map: %p\n", (void *)params->map);
    printf("mlx: %p\n", (void *)params->mlx);
    printf("floor: %s    | r:%d g:%d b:%d\n", params->floor ? "true" : "false", params->txt->f_r, params->txt->f_g, params->txt->f_b);
    printf("ceiling: %s  | r:%d g:%d b:%d\n", params->ceiling ? "true" : "false", params->txt->c_r, params->txt->c_g, params->txt->c_b);
    printf("north: %s  | %p\n", params->north ? "true" : "false", params->txt->no);
    printf("south: %s  | %p\n", params->south ? "true" : "false", params->txt->so);
    printf("west: %s   | %p\n", params->west ? "true" : "false", params->txt->we);
    printf("east: %s   | %p\n", params->east ? "true" : "false",	params->txt->ea);
	printf("player_pos_x: %f\nplayer_pos_y: %f\n", params->map->player.map_x, params->map->player.map_y);
	printf("player_angle: %f\n", params->map->player.angle);
	printf("player_speed: %d\n", params->map->speed);
	printf("minimap_box: %d\n", params->map->minimap_box);
	printf("offset: %d\n", params->map->offset);
	printf("map_size_x: %d\nmap_size_y: %d\n", \
			params->map->size_x, params->map->size_y);
	printf("height: %d\n", params->map->map_height);
	printf("width: %d\n", params->map->map_width);
	printf("total_height: %d\n", params->map->total_height);
	printf("total_width: %d\n", params->map->total_width);

	printf("---------------------- fin info ----------------------\n");
}



parse_error init_game(t_params *params, int fd)
{
	params->txt = malloc(sizeof(t_textures));
	params->lines = get_lines(fd);
	// free_all_mem(&params->memory_blocks);

	/*@todo check if get_next_line can fail, if so, check if it fails or not to stop or preceed execution */
	close(fd);
	char **map = init_params(params);
	init_map(params, map); // will allocate memory for the map and set it to 9's 

	parse_map(params, map);
	init_player(params);
	print_map(params, NULL);
	debug_info(params);
	if (!params->map->map)
		return 1;

	int **map_copy = (int **) copy_2d_array((void **)params->map->map, \
	params->map->map_height, params->map->map_width, sizeof(int));
	check_map(params, params->map->player.map_x, params->map->player.map_y, map_copy);
	free_2d_array((void **)map_copy, params->map->map_height);
	return (VALID);
}

int parse(int argc, char **argv, t_params *params)
{
	int		fd;

	if (argc != 2)
	{
		ft_printf_fd(2, error_msgs[INVALID_NUM_ARGS]);
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_printf_fd(2, error_msgs[INVALID_FILE_EXTENSION]);
		return (1);
	}
	if (check_file_name(argv[1]) != VALID)
	{
		return (1);
	}
	if (init_game(params, fd) != VALID)
	{
		ft_printf_fd(2, error_msgs[INIT_GAME_ERROR]);
		return (1);
	}

	return (0);
}