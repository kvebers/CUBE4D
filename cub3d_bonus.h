/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 03:06:44 by asioud            #+#    #+#             */
/*   Updated: 2023/07/04 16:15:04 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H_BONUS
# define CUB3D_H_BONUS

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include "math.h"
# include <stdbool.h>

# include "libs/libft/includes/libft.h"
# include "libs/MLX42/include/MLX42/MLX42.h"

# include "./src/bonus/init/init_bonus.h"
# include "./src/bonus/parsing/parser_bonus.h"

# define FOV 60
# define SPEED 15
# define HEIGHT 1920
# define WIDTH 1080
# define MINIMAP_BOX WIDTH / 4
# define OFFSET WIDTH / 8

#endif