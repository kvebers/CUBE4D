/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:04:21 by asioud            #+#    #+#             */
/*   Updated: 2023/06/06 04:24:58 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	set_floor(char *str, t_params *p)
{
	if (p->floor)
	{
		ft_putstr_fd("Error\nMultiple floor inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (set_floor_txt(str, p) != VALID)
			ft_putstr_fd("Error\nInvalid floor format\n", 2);
	}
	return (VALID);
}

int	set_ceiling(char *str, t_params *p)
{
	if (p->ceiling)
	{
		ft_putstr_fd("Error\nMultiple ceiling inputs\n", 2);
		return (INVALID);
	}
	else
	{
		if (set_ceiling_txt(str, p) != VALID)
		{
			ft_putstr_fd("Error\nInvalid floor format\n", 2);
			return (INVALID);
		}
	}
	return (VALID);
}

int	set_params(char c, char *str, t_params *p)
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
		return (free(path), INVALID);
	return (free(path), VALID);
}
