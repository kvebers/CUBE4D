/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:33:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:50:41 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector	vector_estimation(int speed, int angle)
{
	t_vector	vector;

	vector.pos_x = speed * cos(angle * M_PI / 180);
	vector.pos_y = speed * sin(angle * M_PI / 180);
	return (vector);
}
