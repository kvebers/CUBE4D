/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:03:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/31 08:23:27 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include "init.h"
#include <math.h>

int32_t	get_pixel_color(int x, int y, mlx_texture_t *texture)
{
	return (rgb(texture->pixels[64 * 4 * y + 4 * x],
			texture->pixels[64 * 4 * 4 + 4 * x + 1],
			texture->pixels[64 * 4 * y + 4 * x + 2],
			texture->pixels[64 * 4 * 4 + 4 * x + 3]));
}

int32_t	render_pixel(t_params *params, t_ray *ray)
{
	(void) ray;
	return (get_pixel_color(0, 0, params->txt->ea));
}

// I did set the player angle in p->map->player->dir_x/dir_y in player.c
// check comment in parser.h
// I changed the conflict we had before 
