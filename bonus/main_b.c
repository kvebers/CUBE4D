/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/20 14:58:14 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser_bonus.h"
#include "../cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_params	params;

	params.lose = 0;
	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	if (params.lose == 1)
	{
		mlx_terminate(params.mlx);
		render_end();
	}
	return (0);
}
