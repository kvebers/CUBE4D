/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:20:07 by asioud            #+#    #+#             */
/*   Updated: 2023/07/07 23:14:45 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	skip_whitespace(char **str)
{
	while (**str && **str == ' ')
		(*str)++;
}

int	set_floor_values(char *str, t_params *p, int count)
{
	int	value;

	value = ft_atoi(str);
	if (value > 255 || value < 0 || !ft_isdigit(*str))
	{
		ft_printf_fd(2, "Error\nInvalid floor values\n");
		cub_free(*p);
	}
	if (count == 0)
		p->txt->f_r = value;
	else if (count == 1)
		p->txt->f_g = value;
	else if (count == 2)
	{
		p->txt->f_b = value;
		p->floor = true;
		return (1);
	}
	return (0);
}

int	set_ceiling_values(char *str, t_params *p, int count)
{
	int	value;

	value = ft_atoi(str);
	if (value > 255 || value < 0 || !ft_isdigit(*str))
	{
		ft_printf_fd(2, "Error\nInvalid ceiling values\n");
		cub_free(*p);
	}
	if (count == 0)
		p->txt->c_r = value;
	else if (count == 1)
		p->txt->c_g = value;
	else if (count == 2)
	{
		p->txt->c_b = value;
		p->ceiling = true;
		return (1);
	}
	return (0);
}

int	set_ceiling_txt(char *str, t_params *p)
{
	int		count;
	float	value;

	if (p->ceiling)
		return (1);
	count = 0;
	str++;
	while (*str)
	{
		skip_whitespace(&str);
		if (count > 0)
		{
			if (*(str++) != ',')
				return (1);
			skip_whitespace(&str);
		}
		if (set_ceiling_values(str, p, count))
			break ;
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		count++;
	}
	return (0);
}

int	set_floor_txt(char *str, t_params *p)
{
	int	count;
	int	value;

	if (p->floor)
		return (1);
	count = 0;
	str++;
	while (*str)
	{
		skip_whitespace(&str);
		if (count > 0)
		{
			if (*(str++) != ',')
				return (1);
			skip_whitespace(&str);
		}
		if (set_floor_values(str, p, count))
			break ;
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		count++;
	}
	return (0);
}
