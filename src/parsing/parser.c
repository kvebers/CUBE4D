/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:15:50 by asioud            #+#    #+#             */
/*   Updated: 2023/05/23 04:54:46 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../cub3d.h"

char	**get_lines(char **lines, char **tmp, int fd)
{
	char	*s = NULL;
	int		i;
	int		j;

	i = 1;
	while (s)
	{
		s = get_next_line(fd);
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
	printf("%s\n", params->lines[0]);
	close(fd);
	
	
	return (VALID);
}