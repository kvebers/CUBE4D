/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/06/02 22:31:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "../cub3d.h"


int	main(int argc, char **argv)
{
	t_params	params;

	system("afplay ./sound/music.mp3 &");
	if (parse(argc, argv, &params) == 0)
		init_cube(&params);
	return (0);
}