/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:31:24 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/03 16:25:58 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include <math.h>

void	shaders(int32_t *red, int32_t *green, int32_t *blue, t_ray *ray)
{
	int	shader_offset;

	shader_offset = ray->distance / 0.03;
	*red = *red - shader_offset + ray->gun_light * 3;
	if (*red < 0)
		*red = 0;
	*blue = *blue - shader_offset + ray->gun_light * 3;
	if (*blue < 0)
		*blue = 0;
	*green = *green - shader_offset + ray->gun_light * 3;
	if (*green < 0)
		*green = 0;
	if (*red > 255)
		*red = 255;
	if (*blue > 255)
		*blue = 255;
	if (*green > 255)
		*green = 255;
}
