/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:02:00 by mrio              #+#    #+#             */
/*   Updated: 2026/05/24 16:02:00 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_open_cell(t_game *game, int x, int y)
{
	char	**grid;

	grid = game->map.grid;
	return (y == 0 || x == 0 || y == game->map.height - 1
		|| x == game->map.width - 1 || grid[y - 1][x] == ' '
		|| grid[y + 1][x] == ' ' || grid[y][x - 1] == ' '
		|| grid[y][x + 1] == ' ');
}

int	check_map_closed(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (c == '0' && is_open_cell(game, x, y))
				return (error_msg("map is not closed by walls"));
			x++;
		}
		y++;
	}
	return (1);
}
