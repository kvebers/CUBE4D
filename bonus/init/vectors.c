/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:33:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/01 16:38:37 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include <stdio.h>
#include "init_bonus.h"
#include "../parsing/parser_bonus.h"
#include <math.h>

t_vector	vector_estimation(int speed, int angle)
{
	t_vector	vector;

	vector.pos_x = speed * cos(angle * M_PI / 180);
	vector.pos_y = speed * sin(angle * M_PI / 180);
	return (vector);
}

