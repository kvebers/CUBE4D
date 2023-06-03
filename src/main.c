/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/03 19:38:46 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "../cub3d.h"

void check_leaks()
{
	system("leaks cub3D");
}
	
int	main(int argc, char **argv)
{
	t_params	params;

	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
		
	free_2d(params.lines);
	
	mlx_delete_texture(params.txt->no);
	mlx_delete_texture(params.txt->so);
	mlx_delete_texture(params.txt->we);
	mlx_delete_texture(params.txt->ea);
	free(params.txt);
	
	
	// check_leaks();
	return (0);
}
