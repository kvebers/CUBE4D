/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/05/23 07:35:33 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../cub3d.h"

char	**parse_parameters(t_param *p, char **lines)
{
	int i;
	int j;
	int map;

	i = 0;
	map = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!choose_param(lines[i][j], lines[i], p))
		{
			return (&lines[i]);
		}
		i++;
	}
	put_error("ERROR\nNO MAP FOUND\n", p);
	return (lines);
}

char	**get_lines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;

	i = 1;
	s = get_next_line(fd);
	while (s)
	{
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		if (tmp)
			while (tmp[j])
			{
				lines[j] = tmp[j];
				j++;
			}
		free(tmp);
		lines[j++] = s;
		lines[j] = 0;
		i++;
		s = get_next_line(fd);
	}
	return (lines);
}

parse_error parse(int argc, char **argv, t_params *params)
{
	int		fd;
	char	**tmp = NULL;


	if (argc > 3 || argc < 2)
		return (WRONG_NUM_ARGS);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (INVALID_FILE);
	params->lines = get_lines(params->lines, tmp, fd);
	close(fd);
	
	
	return (VALID);
}