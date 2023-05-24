/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:20:07 by asioud            #+#    #+#             */
/*   Updated: 2023/05/24 05:32:38 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include "parser.h"
#include <stdbool.h>

void	make_sky(char *str, t_params *p)
{
	if (p->skyfloor)
		return (MANY_CEILING_INPUT);
	
	int count = 0; // Counter to keep track of the expected number of values
	
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		
		if (count > 0)
		{
			if (*(str++) != ',')
				return (INVALID_CEILING_FORMAT);
			
			while (*str == ' ')
				str++;
		}
		
		float value = ft_cubatoi_f(str);
		if (!ft_isdigit(*str) || value == -1)
			return (INVALID_CEILING_VALUES);
		
		if (count == 0)
			p->mlx->sr = value;
		else if (count == 1)
			p->mlx->sg = value;
		else if (count == 2)
		{
			p->mlx->sb = value;
			p->skyfloor = 1;
			break;
		}
		
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		
		count++;
	}
}

void	make_floor(char *str, t_params *p)
{
	int		count;
	float	value;

	if (p->floor)
		return (MANY_FLOOR_INPUT);
	count = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;

		if (count > 0)
		{
			if (*(str++) != ',')
				return (INVALID_FLOOR_FORMAT);
			
			while (*str == ' ')
				str++;
		}
		value = ft_atoll(str);
		if (!ft_isdigit(*str) || value == -1)
			return (INVALID_FLOOR_VALUES);
		
		if (count == 0)
			p->txt->f_r = value;
		else if (count == 1)
			p->txt->f_g = value;
		else if (count == 2)
		{
			p->txt->f_b = value;
			p->floor = true;
			break;
		}
		
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		
		count++;
	}
}

