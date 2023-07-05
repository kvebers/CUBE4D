/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/07/05 22:36:05 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"

void	check_leaks(void)
{
	system("leaks cub3D");
}

void	cub_free(t_params p)
{
	free_all_mem(&p.mem);
	if (p.lines)
		free_2d(p.lines);
	if (p.txt->no)
		mlx_delete_texture(p.txt->no);
	if (p.txt->so)
		mlx_delete_texture(p.txt->so);
	if (p.txt->we)
		mlx_delete_texture(p.txt->we);
	if (p.txt->ea)
		mlx_delete_texture(p.txt->ea);
	// if (p.map->map)
	// 	free_2d_array((void **)p.map->map, p.map->map_height);
	check_leaks();
	exit (1);
}

int	main(int argc, char **argv)
{
	t_params	params;

	params = (t_params){0};
	params.map = &(t_map){0};
	params.txt = &(t_textures){0};
	if (parse(argc, argv, &params) == 0)
	{	
		init_cube(&params);
		cub_free(params);
	}
	return (0);
}
