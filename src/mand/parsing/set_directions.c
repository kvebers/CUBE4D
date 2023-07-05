/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:12:46 by asioud            #+#    #+#             */
/*   Updated: 2023/07/05 22:37:01 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

parse_error	set_north(char *path, t_params *p)
{
	if (p->north)
		return (MULT_NORTH_INPUT);
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd(error_msgs[INVALID_NORTH_PATH], 2);
			cub_free(*p);
		}
		else
			p->txt->no = mlx_load_png(path);
		p->north = true;
	}
	free(path);
	return (VALID);
}

parse_error	set_south(char *path, t_params *p)
{
	if (p->south)
		return (MULT_SOUTH_INPUT);
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd(error_msgs[INVALID_SOUTH_PATH], 2);
			cub_free(*p);
		}
		else
			p->txt->so = mlx_load_png(path);
		p->south = true;
	}
	free(path);
	return (VALID);
}

parse_error	set_west(char *path, t_params *p)
{
	if (p->west)
		return (MULT_WEST_INPUT);
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd(error_msgs[INVALID_WEST_PATH], 2);
			cub_free(*p);
		}
		else
			p->txt->we = mlx_load_png(path);
		p->west = true;
	}
	free(path);
	return (VALID);
}

parse_error	set_east(char *path, t_params *p)
{
	if (p->east)
		return (MULT_NORTH_INPUT);
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd(error_msgs[INVALID_EAST_PATH], 2);
			cub_free(*p);
		}
		else
			p->txt->ea = mlx_load_png(path);
		p->east = true;
	}
	free(path);
	return (VALID);
}
