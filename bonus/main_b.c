/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/19 14:33:02 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser_bonus.h"
#include "../cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_params	params;

	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	
	return (0);
}
