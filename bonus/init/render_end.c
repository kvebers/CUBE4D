/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:34:09 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/21 13:09:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include "math.h"

void load_png(t_pain *params)
{
    params->end_pain[0] = mlx_load_png("textures/e1.png");
    params->end_pain[1] = mlx_load_png("textures/e2.png");
    params->end_pain[2] = mlx_load_png("textures/e3.png");
    params->end_pain[3] = mlx_load_png("textures/e4.png");
    params->end_pain[4] = mlx_load_png("textures/e5.png");
    params->end_pain[5] = mlx_load_png("textures/e6.png");
    params->end_pain[6] = mlx_load_png("textures/e7.png");
}

void delete_pain(t_pain *params)
{
    mlx_delete_texture(params->end_pain[0]);
    mlx_delete_texture(params->end_pain[1]);
    mlx_delete_texture(params->end_pain[2]);
    mlx_delete_texture(params->end_pain[3]);
    mlx_delete_texture(params->end_pain[4]);
    mlx_delete_texture(params->end_pain[5]);
    mlx_delete_texture(params->end_pain[6]);
}

void    loop_end(void *pain)
{
    t_pain      *params;
    mlx_image_t *img;

    params = (t_pain *) pain;
    if (params->frame_pain % 5 == 0)
    {
        img = mlx_texture_to_image(params->mlx, params->end_pain[params->frame_pain / 5]);
        mlx_image_to_window(params->mlx, img, 0, 0);
    }
    if (params->frame_pain % 5 == 4)
        mlx_delete_image(params->mlx, img);
    params->frame_pain++;
    if (params->frame_pain == 34)
        mlx_close_window(params->mlx);
}

void render_end()
{
    t_pain  param;

    param.frame_pain = 0;
    load_png(&param);
    param.mlx = mlx_init(2560, 1440, "Jump", false);
    system("afplay ./sound/demon.mp3 &");
    mlx_loop_hook(param.mlx, &loop_end, &param);
    mlx_loop(param.mlx);
    delete_pain(&param);
}