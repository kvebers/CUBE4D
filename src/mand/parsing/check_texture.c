/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:20:07 by asioud            #+#    #+#             */
/*   Updated: 2023/06/07 05:05:07 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void skip_whitespace(char **str)
{
	while (**str && **str == ' ')
		(*str)++;
}

int	set_ceiling_txt(char *str, t_params *p)
{
	int		count;
	float	value;

	count = 0;
	str++;
	while (*str)
	{
		skip_whitespace(&str);
		if (count > 0)
		{
			if (*(str++) != ',')
				return (ft_putstr_fd("Error\nInvalid ceiling format\n", 2), INVALID);
			skip_whitespace(&str);
		}
		value = ft_atoi(str);
		if (!ft_isdigit(*str) || value == -1)
			return (ft_putstr_fd("Error\nInvalid ceiling values\n", 2), INVALID);
		if (count == 0)
			p->txt->c_r = value;
		else if (count == 1)
			p->txt->c_g = value;
		else if (count == 2)
		{
			p->txt->c_b = value;
			p->ceiling = true;
			break ;
		}
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		count++;
	}
	return (VALID);
}

int	set_floor_txt(char *str, t_params *p)
{
	int count;
	int value;

	count = 0;
	str++;
	while (*str)
	{
		skip_whitespace(&str);
		if (count > 0)
		{
			if (*(str++) != ',')
				return (ft_putstr_fd("Error\nInvalid floor format\n", 2), INVALID);
			skip_whitespace(&str);
		}
		value = ft_atoi(str);
		if (!ft_isdigit(*str) || value == -1)
			return (ft_putstr_fd("Error\nInvalid floor values\n", 2), INVALID);
		if (count == 0)
			p->txt->f_r = value;
		else if (count == 1)
			p->txt->f_g = value;
		else if (count == 2)
		{
			p->txt->f_b = value;
			p->floor = true;
			break ;
		}
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		count++;
	}
	return (VALID);
}