/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:05:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/02 22:38:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include "../../cub3d_bonus.h"
# include "../../libs/MLX42/include/MLX42/MLX42.h"

# define EPSILON 0.000001
# define PRECISION 64

typedef struct s_params	t_params;
typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;
//INIT.c
int			init_cube(t_params *params);
//UTILS.c
uint32_t	rgb(int r, int g, int b, int a);
void		draw_line(t_params *params, t_ray *ray, int color);
double		deg_to_rad(double deg);
double		calculate_atan(int x_enemy,
				int y_enemy, int x_player, int y_player);
//KEYHOOKS.c
void		keyhook(void *param);
void		escape(mlx_key_data_t keydata, void *params);
//ROTATION.c
void		arrow_pressed_l(t_params *params);
void		arrow_pressed_r(t_params *params);
//MINIMAP.c
void		render_minimap(t_params *params);
void		draw_pain(t_params *params);
//RENDERMAP.c
void		render_map(t_params *params);
void		calculate_distance_helper(t_params *params, t_ray *ray);
//RENDERBACKGROUND.c
void		render_skybox(t_params *params);
//INIT.c
void		test_textures(t_params *params);
//VECTORS.c
t_vector	vector_estimation(int speed, int angle);
//MOVE_VALID.c
void		check_valid_move1(t_params *params, double posx, double posy);
//DEBUG.c
void		debug_ray(t_ray *ray);
//render_texture.c
void		render_wall_line(t_params *params, t_ray *ray, int x, int y);
//mousehook.c
void		mousehook(t_params *params);
void		render_pause(t_params *params);
// shaders.c
void		shaders(int32_t *red, int32_t *green, int32_t *blue, t_ray *ray);
//doors.c
void		spawn_doors(t_params *params);
void		open_doors(t_params *params);
//enemy.c
void		spawn_duck(t_params *params, int x, int y);
void		render_enemy(t_params *params, t_ray *ray);
void		update_enemy(t_params *params);
//sound.c
void		check_sound(void);
#endif