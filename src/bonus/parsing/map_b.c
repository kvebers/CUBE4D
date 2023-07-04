/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:09:33 by asioud            #+#    #+#             */
/*   Updated: 2023/07/04 16:13:44 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

char	put_chars(char c);

void	check_map(t_params *p, int x, int y, int **map)
{
	if (map[x][y] == '1' || map[x][y] == '3' || map[x][y] == '4')
		return ;
	if (map[x][y] == '9')
		return ;
	if (map[x][y] == '\n' || map[x][y] == '\0')
		return ;
	if ((x < 0 || y < 0 || x == p->map->map_height))
	{
		ft_putstr_fd(error_msgs[MAP_NOT_CLOSED], 2);
		return ;
	}
	if (map[x][y] == -1)
	{
		ft_putstr_fd(error_msgs[MAP_NOT_CLOSED], 2);
		return ;
	}
	if (map[x][y] == '0')
		map[x][y] = '3';
	if (map[x][y] == '2')
		map[x][y] = '4';
	check_map(p, x + 1, y, map);
	check_map(p, x, y + 1, map);
	check_map(p, x - 1, y, map);
	check_map(p, x, y - 1, map);
}

/**
 * @brief Convert the map from a lines array to a 2D int array 
 * @param p The params struct
 * @param map The lines array
 */
void	parse_map(t_params *p, char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	i = 0;
	while (map[i])
	{
		y = 0;
		j = 0;
		while (map[i][j])
		{
            if (map[i][j] == ' ' || map[i][j] == '\n')
            {
                p->map->map[x][y++] = (int)9;
                j++;
            }
			else if (map[i][j])
				p->map->map[x][y++] = (int)map[i][j++];
		}
		i++;
		x++;
	}
		p->map->map_height = i; /* to change later */
}

/**
 * @brief Initializes the size of the map and allocates memory for the map array
 * @param p 
 */
void	init_map(t_params *p, char **map)
{
	int i;
	int j;
	int len;
	int emptyline;

	i = 0;
	emptyline = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			emptyline = 1;
		if (map[i][j] && emptyline)
			ft_putstr_fd("ERROR\nAdditional Input after map\n", 2);
		i++;
	}
	p->map = (t_map *)malloc(sizeof(t_map));
	p->map->map_height = i;
	i = 0;
	j = 0;
	len = 0;
	int biglen = 0;
	while (map[i])
	{
		len = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\n' && map[i][j] != '\0')
				len++;
			j++;
		}
		if (len > biglen)
			biglen = len;
		i++;
	}
	p->map->map_width = biglen;
	p->map->map = (int **)malloc(p->map->map_height * sizeof(int *));
	i = 0;
	while (i < p->map->map_height)
	{
		p->map->map[i] = (int *)malloc(p->map->map_width * sizeof(int));
		ft_memset(p->map->map[i], 9, p->map->map_width * sizeof(int));
		i++;
	}
}

void	print_map(t_params *p, char **map)
{
	printf("\n");
	int i = 0;
	int j = 0;
	while (i < p->map->map_height)
	{
		j = 0;
		while (j < p->map->map_width)
		{
			put_chars((char)p->map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
    (void)map;
}

char	put_chars(char c)
{
	char	colored_0[] = "\e[1;37m0\e[0m";
	char	colored_1[] = "\e[1;31m1\e[0m";
	char	colored_e[] = "\e[1;32mE\e[0m";
	char	colored_s[] = "\e[1;32mS\e[0m";
	char	colored_w[] = "\e[1;35mW\e[0m";
	char	colored_n[] = "\e[1;34mN\e[0m";
	char	colored_x[] = "\e[1;34mX\e[0m";
	char	colored_plus[] = "\e[1;34m+\e[0m";
	char	colored_9[] = "\e[1;33m9\e[0m";

	if (c == '0')
		write(1, &colored_0, 13);
	else if (c == '1')
		write(1, &colored_1, 13);
	else if (c == 'N')
		write(1, &colored_n, 13);
	else if (c == 'S')
		write(1, &colored_s, 13);
	else if (c == 'W')
		write(1, &colored_w, 13);
	else if (c == 'E')
		write(1, &colored_e, 13);
	else if (c == '+')
		write(1, &colored_plus, 13);
	else if (c == 9)
		write(1, &colored_9, 13);
	else if (c == 'X')
		write(1, &colored_x, 13);
	else if (c == ' ')
		write(1, " ", 1);
	return (0);
}