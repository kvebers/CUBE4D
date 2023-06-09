/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:05:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 15:49:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define EPSILON 0.000001
# define PRECISION 64

typedef struct s_params	t_params;
typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;
//INIT.c
int						init_cube(t_params *params);
//UTILS.c
uint32_t				rgb(int r, int g, int b, int a);
void					draw_line(t_params *params, t_ray *ray, int color);
double					deg_to_rad(double deg);
//KEYHOOKS.c
void					keyhook(mlx_key_data_t key_data, void *param);
//ROTATION.c
void					arrow_pressed_l(t_params *params);
void					arrow_pressed_r(t_params *params);
//MINIMAP.c
void					render_minimap(t_params *params);
//RENDERMAP.c
void					render_map(t_params *params);
void					render_skybox(t_params *params);
//INIT.c
void					test_textures(t_params *params);
//VECTORS.c
t_vector				vector_estimation(int speed, int angle);
//MOVE_VALID.c
void					check_valid_move1(t_params *params, double posx,
							double posy);
//DEBUG.c
void					debug_ray(t_ray *ray);
//render_texture.c
void					render_wall_line(t_params *params, t_ray *ray, int x,
							int y);

#endif