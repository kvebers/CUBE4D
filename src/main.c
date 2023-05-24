/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:09:48 by asioud            #+#    #+#             */
/*   Updated: 2023/05/24 08:42:37 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parser.h"
#include "../cub3d.h"


int	main(int argc, char **argv)
{
	t_params	params;
	parse_error	error;

	
	error = parse(argc, argv, &params);
	if (error == VALID)
	{
		// init_cube(&params);
		ft_putstr_fd(error_msgs[error], 2);
		return (0);
	}
	else
	{
		ft_putstr_fd(error_msgs[error], 2);
		return (1);
	}

	return (0);
}
