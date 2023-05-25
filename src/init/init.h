/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:05:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/24 17:21:45 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../../cub3d.h"
# include "../../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_params	t_params;

//INIT.c
int			init_cube(t_params *params);
//UTILS.c
uint32_t	rgb(int r, int g, int b, int a);
int			count_lines(char **lines);
int			get_longest_line(char **lines);
//KEYHOOKS.c
void		keyhook(mlx_key_data_t key_data, void *param);
//MINIMAP.c
void		render_minimap(t_params *params);
//RENDERMAP.c
void		render_map(t_params *params);
void		render_skybox(t_params *params);
//INIT.c
void		test_textures(t_params *params);

#endif