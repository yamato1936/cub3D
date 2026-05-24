/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cells.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:42 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:51:37 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player(t_game *game, int x, int y, char dir)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (dir == 'N')
		game->player = (t_player){x + 0.5, y + 0.5, 0, -1, PLANE_LEN, 0};
	else if (dir == 'S')
		game->player = (t_player){x + 0.5, y + 0.5, 0, 1, -PLANE_LEN, 0};
	else if (dir == 'E')
		game->player = (t_player){x + 0.5, y + 0.5, 1, 0, 0, PLANE_LEN};
	else if (dir == 'W')
		game->player = (t_player){x + 0.5, y + 0.5, -1, 0, 0, -PLANE_LEN};
}

static int	scan_cell(t_game *game, int x, int y, int *players)
{
	char	**grid;

	grid = game->map.grid;
	if (grid[y][x] != ' ' && grid[y][x] != '0' && grid[y][x] != '1'
		&& !is_player_char(grid[y][x]))
		return (error_msg("invalid map character"));
	if (is_player_char(grid[y][x]))
	{
		set_player(game, x, y, grid[y][x]);
		grid[y][x] = '0';
		(*players)++;
	}
	return (1);
}

int	scan_map_cells(t_game *game)
{
	int		x;
	int		y;
	int		players;

	players = 0;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (!scan_cell(game, x, y, &players))
				return (0);
		}
	}
	if (players != 1)
		return (error_msg("map must contain exactly one player"));
	return (1);
}
