/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:05:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/23 18:47:00 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../../cub3d.h"
# include "../../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_params	t_params;

int			init_cube(t_params *params);
uint32_t	rgb(int r, int g, int b, int a);

#endif