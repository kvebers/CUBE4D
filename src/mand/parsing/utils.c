/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:23:25 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 01:39:53 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**extend_lines_array(char **lines, char *s, int i)
{
	char	**tmp;
	int		j;

	tmp = lines;
	lines = malloc((i + 1) * sizeof(char *));
	if (tmp)
	{
		j = 0;
		while (tmp[j])
		{
			lines[j] = tmp[j];
			j++;
		}
		free(tmp);
	}
	lines[j++] = s;
	lines[j] = 0;
	return (lines);
}

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
