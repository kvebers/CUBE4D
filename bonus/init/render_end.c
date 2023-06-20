/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:34:09 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/20 15:16:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include "math.h"

void render_end()
{
    mlx_t *mlx;
    mlx_texture_t *txt;
    mlx_image_t *img;
    
    mlx = mlx_init(2560, 1440, "Cub3d", false);
    system("afplay ./sound/Swoosh.mp3 &");
    txt = mlx_load_png("textures/jump.png");
    img = mlx_texture_to_image(mlx, txt);
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
}