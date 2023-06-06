/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:51:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:47:57 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_gun(t_params *params)
{
	if (params->gun_state == 0)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun0);
	else if (params->gun_state == 1 || params->gun_state == 6)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun3);
	else if (params->gun_state == 2 || params->gun_state == 5)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun2);
	else if (params->gun_state == 3 || params->gun_state == 4)
		params->txt->gun = mlx_texture_to_image(params->mlx, params->txt->gun1);
	mlx_image_to_window(params->mlx, params->txt->gun,
		params->gunx + 10, params->guny + 10);
	params->gunx = 0;
	params->guny = 0;
	if (params->gun_state == 4)
		system("afplay ./sound/Gunfire.mp3 &");
	if (params->gun_state > 0)
		params->gun_state--;
}

void	init_gun(t_params *params)
{
	params->gunx = 0;
	params->guny = 0;
	params->gun_state = 0;
	params->txt->gun0 = mlx_load_png("textures/gun0.png");
	params->txt->gun1 = mlx_load_png("textures/gun1.png");
	params->txt->gun2 = mlx_load_png("textures/gun2.png");
	params->txt->gun3 = mlx_load_png("textures/gun3.png");
}

void	gun_stuff(t_params *params)
{
	mlx_delete_image(params->mlx, params->txt->gun);
	render_gun(params);
	params->txt->gun->instances->z = 4;
	if (params->fps % 5 == 0)
	{
		mlx_delete_image(params->mlx, params->txt->ground);
		render_skybox(params);
		render_map(params);
		mlx_delete_image(params->mlx, params->txt->minimap);
		render_minimap(params);
		params->gunx = params->gunx + 5;
		params->txt->ground->instances->z = 2;
		params->txt->minimap->instances->z = 3;
	}
}
