/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/04 02:03:42 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"

void check_leaks()
{
	system("leaks cub3D");
}

void cub_free(t_params p)
{
	free_2d(p.lines);
	mlx_delete_texture(p.txt->no);
	mlx_delete_texture(p.txt->so);
	mlx_delete_texture(p.txt->we);
	mlx_delete_texture(p.txt->ea);
	free_2d_array((void **)p.map->map, p.map->map_height);
	free(p.map);
}

int	main(int argc, char **argv)
{
	t_params	params;

	params = (t_params){0};
	params.map = &(t_map){0};
	params.txt = &(t_textures){0};
	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	cub_free(params);
	check_leaks();
	return (0);
}
