/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:23:25 by asioud            #+#    #+#             */
/*   Updated: 2023/07/06 02:40:24 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	line_init(char **lines, char **tmp, int i, char *s)
{
	lines = NULL;
	tmp = NULL;
	i = 1;
}

char	**get_lines(int fd, t_params *p)
{
	char	**lines;
	char	**tmp;
	char	*s;
	int		i;
	int		j;

	line_init(lines, tmp, i, s);
	s = get_next_line(fd);
	while (s)
	{
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
		i++;
		s = get_next_line(fd);
		free(tmp);
	}
	return (free(s), lines);
}
