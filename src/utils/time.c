/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:30:32 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:29 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	update_timing(t_game *game)
{
	long	now;
	double	delta;

	now = timestamp_ms();
	delta = 0.016;
	if (game->last_tick > 0)
		delta = (now - game->last_tick) / 1000.0;
	if (delta < 0.001)
		delta = 0.001;
	if (delta > 0.05)
		delta = 0.05;
	game->last_tick = now;
	game->move_speed = delta * 3.0;
	game->rot_speed = delta * 2.2;
}
