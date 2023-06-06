/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:44:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/03 18:57:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"

void    free_textures(t_params *params)
{
    mlx_delete_texture(params->txt->gun0);
    mlx_delete_texture(params->txt->gun1);
    mlx_delete_texture(params->txt->gun2);
    mlx_delete_texture(params->txt->gun3);
    mlx_delete_texture(params->txt->ea);
    mlx_delete_texture(params->txt->no);
    mlx_delete_texture(params->txt->we);
    mlx_delete_texture(params->txt->so);
    mlx_delete_texture(params->map->def);
    mlx_delete_texture(params->map->door);
    mlx_delete_texture(params->txt->pause_t);
}