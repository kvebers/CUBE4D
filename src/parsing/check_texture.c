/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:20:07 by asioud            #+#    #+#             */
/*   Updated: 2023/05/24 10:06:55 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include "parser.h"
#include <stdbool.h>

parse_error	set_ceiling(char *str, t_params *p)
{
	int		count;
	float	value;
	
	if (p->ceiling)
		return (MANY_CEILING_INPUT);
	
	count = 0;
	while (*str)
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
		value = ft_cubatoi_f(str);
		if (!ft_isdigit(*str) || value == -1)
			return (INVALID_CEILING_VALUES);
		
		if (count == 0)
			p->txt->c_r = value;
		else if (count == 1)
			p->txt->c_g = value;
		else if (count == 2)
		{
			p->txt->c_b = value;
			p->ceiling = true;
			break;
		}
		
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		count++;
	}
	return (VALID);
}

// parse_error	set_floor(char *str, t_params *p)
// {
// 	int		count;
// 	int	value;

// 	if (p->floor)
// 		return (MANY_FLOOR_INPUT);
// 	count = 0;
// 	while (*str != '\0')
// 	{
// 		while (*str == ' ')
// 			str++;

// 		if (count > 0)
// 		{
// 			if (*(str++) != ',')
// 				return (INVALID_FLOOR_FORMAT);
			
// 			while (*str == ' ')
// 				str++;
// 		}
// 		value = ft_cubatoi_f(str);
// 		printf("\nfloor value: %s, %d\n", str, value);
// 		if (!ft_isdigit(*str) || value == -1)
// 			return (INVALID_FLOOR_VALUES);
		
// 		if (count == 0)
// 			p->txt->f_r = value;
// 		else if (count == 1)
// 			p->txt->f_g = value;
// 		else if (count == 2)
// 		{
// 			p->txt->f_b = value;
// 			p->floor = true;
// 			break;
// 		}
		
// 		while (ft_isdigit(*str) || *str == ' ')
// 			str++;
		
// 		count++;
// 	}
// 	return (VALID);
// }

