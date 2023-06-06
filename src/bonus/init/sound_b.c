/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:36:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/06 20:50:23 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_sound(void)
{
	int	result;

	result = system("pgrep afplay > /dev/null");
	if (result != 0)
		system("afplay ./sound/music.mp3 &");
}
