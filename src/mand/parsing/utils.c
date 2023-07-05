/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:23:25 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 00:23:47 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_lines(int fd, t_params *p)
{
	char	**lines;
	char	*s;
	int		i;

	lines = NULL;
	i = 1;
	s = get_next_line(fd);
	while (s)
	{
		lines = extend_lines_array(lines, s, i);
		i++;
		s = get_next_line(fd);
	}
	free(s);
	return (lines);
}
