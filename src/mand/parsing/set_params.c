/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:04:21 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 13:57:52 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_floor(char *str, t_params *p)
{
	if (p->floor)
	{
		ft_putstr_fd("Error\nMultiple floor inputs\n", 2);
		cub_free(*p);
	}
	else
	{
		if (set_floor_txt(str, p) != 0)
			ft_putstr_fd("Error\nInvalid floor format\n", 2);
	}
	return (0);
}

int	set_ceiling(char *str, t_params *p)
{
	if (p->ceiling)
		ft_putstr_fd("Error\nMultiple ceiling inputs\n", 2);
	else
	{
		if (set_ceiling_txt(str, p) != 0)
			ft_putstr_fd("Error\nInvalid floor format\n", 2);
	}
	return (0);
}

int	set_params(char c, char *str, t_params *p)
{
	char	*path;

	path = ft_strtrim(str + 3, "\n");
	skip_whitespace(&str);
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
		return (free(path), 1);
	else if (c == '\n')
		return (free(path), 0);
	else
		return (ft_putstr_fd("Error\nInvalid input\n", 2), cub_free(*p), 1);
	return (free(path), 0);
}
