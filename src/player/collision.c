/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:49 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:06 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	map_at(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return (' ');
	return (game->map.grid[y][x]);
}

int	is_walkable(t_game *game, double x, double y)
{
	char	cell;

	cell = map_at(game, (int)x, (int)y);
	return (cell != '1' && cell != ' ');
}
