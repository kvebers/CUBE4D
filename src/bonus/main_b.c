/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/07/04 16:14:39 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_leaks(void)
{
	system("leaks cub4D");
}

void	cub_free(t_params p)
{
	free_2d(p.lines);
	free_2d_array((void **)p.map->map, p.map->map_height);
	free(p.map);
	
}


int	main(int argc, char **argv)
{
	t_params	params;

	params.lose = 0;
	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	if (params.lose == 1)
	{
		mlx_terminate(params.mlx);
		free_textures(&params);
		cub_free(params);
		render_end();
	}
	else
	{
		mlx_terminate(params.mlx);
		free_textures(&params);
		cub_free(params);
	}
	check_leaks();
	return (0);
}
