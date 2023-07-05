/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:04:21 by asioud            #+#    #+#             */
/*   Updated: 2023/07/05 22:44:32 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

parse_error	set_floor(char *str, t_params *p)
{
	parse_error	err;

	if (p->floor)
	{
		return (MULT_NORTH_INPUT);
	}
	else
	{
		if ((err = set_floor_txt(str, p)) != VALID)
			ft_putstr_fd(error_msgs[INVALID_FLOOR_FORMAT], 2);
	}
	return (err);
}

parse_error	set_ceiling(char *str, t_params *p)
{
	parse_error	err;

	if (p->ceiling)
		return (MULT_SOUTH_INPUT);
	else
	{
		if ((err = set_ceiling_txt(str, p)) != VALID)
			ft_putstr_fd(error_msgs[INVALID_FLOOR_FORMAT], 2);
	}
	return (err);
}

parse_error	set_params(char c, char *str, t_params *p)
{
	char	*path;

	path = ft_strtrim(str + 3, "\n");
	while (*str == ' ')
		str++;
	if (c == 'F' && *(str + 1) == ' ')
		return (free(path), set_floor(str, p));
	else if (c == 'C' && *(str + 1) == ' ')
		return (free(path), set_ceiling(str, p));
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		return (set_north(path, p));
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		return (set_south(path, p));
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		return (set_west(path, p));
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		return (set_east(path, p));
	else if (c == '1' || c == '2' || c == '0')
		return (free(path), INVALID_IDENTIFIERS);
	else if (c == '\n')
		return (free(path), VALID);
	else
	{
		ft_putstr_fd("Error\nWrong Input\n", 2);
		cub_free(*p);
	}
	return (free(path), VALID);
}
