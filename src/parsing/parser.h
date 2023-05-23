/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:42:57 by asioud            #+#    #+#             */
/*   Updated: 2023/05/23 04:37:47 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum {
	VALID,
	WRONG_NUM_ARGS,
	INVALID_ARG,
	INVALID_FILE,
} parse_error;

static char *error_msgs[10] = {
	[VALID]             =   "VALID",
	[WRONG_NUM_ARGS]    =   "Wrong number of arguments",
	[INVALID_FILE]      =   "Invalid map file or wrong path",
};

typedef struct s_params {
	char **lines;
	
} t_params;


parse_error parse(int argc, char **argv, t_params *params);



#endif