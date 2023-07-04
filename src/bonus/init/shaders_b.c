/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:31:24 by kvebers           #+#    #+#             */
/*   Updated: 2023/07/04 16:13:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	shaders(int32_t *red, int32_t *green, int32_t *blue, t_ray *ray)
{
	int	shader_offset;

	shader_offset = ray->distance / 0.03 + ray->global_light;
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
