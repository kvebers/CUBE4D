/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:23:25 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 15:08:00 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**manage_memory_for_lines(char **lines, char *s, int i)
{
	char	**tmp;
	int		j;

	tmp = lines;
	j = 0;
	lines = malloc((i + 1) * sizeof(char *));
	if (tmp)
	{
		while (tmp[j])
		{
			lines[j] = tmp[j];
			j++;
		}
	}
	lines[j++] = s;
	lines[j] = 0;
	free(tmp);
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
		lines = manage_memory_for_lines(lines, s, i);
		i++;
		s = get_next_line(fd);
	}
	return (free(s), lines);
}
