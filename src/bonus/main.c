/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/06 21:08:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


void	cub_free(t_params p)
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

	system("afplay ./sound/music.mp3 &");
	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	else
		cub_free(params);
	return (0);
}