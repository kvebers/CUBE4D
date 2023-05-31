/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:03:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/31 10:08:00 by kvebers          ###   ########.fr       */
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

void	render_wall_line(t_params *params, t_ray *ray, mlx_texture_t *txt)
{
	double	y_inc;
	int y;
	
	y_inc = ray->wall_height * 2 / 	txt->height;
	while (y < txt->height)
	{
		
		y++;
	}
	
	
}


// I did set the player angle in p->map->player->dir_x/dir_y in player.c
// check comment in parser.h
// I changed the conflict we had before 
// void drawTexture(int x, int wallHeight, int texturePositionX, Texture texture) {
//     float yIncrementer = (wallHeight * 2) / texture.height;
//     float y = data.projection.halfHeight - wallHeight;
//     int color = 0;
//     for (int i = 0; i < texture.height; i++) {
//         if (texture.id) {
//             color = texture.data[texturePositionX + i * texture.width];
//         } else {
//             color = texture.colors[texture.bitmap[i][texturePositionX]];
//         }
//         drawLine(x, y, (int)(y + yIncrementer + 2), color);
//         y += yIncrementer;
//     }
// }