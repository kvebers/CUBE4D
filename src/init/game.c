/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/25 23:36:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	game_loop(t_params *params)
{
	render_skybox(params);
	render_map(params);
	render_minimap(params);
	mlx_key_hook(params->mlx, keyhook, params);
	mlx_loop(params->mlx);
}

//tocheckout add flexible map scaling
//@todo add variables for the map size
//@todo add flexible map size

int	init_cube(t_params *params)
{
	test_textures(params);
	params->mlx = mlx_init(1920, 1080, "Cub3d", true);
	game_loop(params);
	return (0);
}
