/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:12:46 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 04:51:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_north(char *path, t_params *p)
{
	if (p->north)
	{
		ft_putstr_fd("Error\nMultiple north inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd("Error\nInvalid north path\n", 2);
			free(path);
			return (INVALID);
		}
		else
			p->txt->no = mlx_load_png(path);
		p->north = true;
	}
	free(path);
	return (VALID);
}

int	set_south(char *path, t_params *p)
{
	if (p->south)
	{
		ft_putstr_fd("Error\nMultiple south inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd("Error\nInvalid south path\n", 2);
			free(path);
			return (INVALID);
		}
		else
			p->txt->so = mlx_load_png(path);
		p->south = true;
	}
	free(path);
	return (VALID);
}

int	set_west(char *path, t_params *p)
{
	if (p->west)
	{
		ft_putstr_fd("Error\nMultiple east inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd("Error\nInvalid west path\n", 2);
			free(path);
			return (INVALID);
		}
		else
			p->txt->we = mlx_load_png(path);
		p->west = true;
	}
	free(path);
	return (VALID);
}

int	set_east(char *path, t_params *p)
{
	if (p->east)
	{
		ft_putstr_fd("Error\nMultiple east inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (open(path, O_RDONLY) == -1)
		{
			ft_putstr_fd("Error\nInvalid east path\n", 2);
			free(path);
			return (INVALID);
		}
		else
			p->txt->ea = mlx_load_png(path);
		p->east = true;
	}
	free(path);
	return (VALID);
}
