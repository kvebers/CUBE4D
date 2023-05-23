/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/23 15:19:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"

void	render_map(t_params *params)
{
	(void) params;
}

void	render_minimap(t_params *params)
{
	(void) params;
}

void	game_loop(t_params *params)
{
	render_minimap(params);
	render_map(params);
	mlx_loop(params->mlx);
}

//tocheckout add flexible map scaling
//todo add variables for the map size
//todo 
int	init_cube(t_params *params)
{
	params->mlx = mlx_init(1920, 1080, "Cub3d", true);
	game_loop(params);
	return (0);
}
