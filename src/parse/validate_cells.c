/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cells.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:42 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
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

static int	mark_player_tile(t_game *game, char **grid, int x, int y)
{
	set_player(game, x, y, grid[y][x]);
	grid[y][x] = '0';
	return (1);
}

int	scan_map_cells(t_game *game)
{
	int		x;
	int		y;
	int		players;
	char	**grid;

	grid = game->map.grid;
	players = 0;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (grid[y][x] != ' ' && grid[y][x] != '0' && grid[y][x] != '1'
				&& !is_player_char(grid[y][x]))
				return (error_msg("invalid map character"));
			if (is_player_char(grid[y][x]))
				players += mark_player_tile(game, grid, x, y);
		}
	}
	if (players != 1)
		return (error_msg("map must contain exactly one player"));
	return (1);
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
			if (c == '0' && (y == 0 || x == 0 || y == game->map.height - 1
					|| x == game->map.width - 1 || game->map.grid[y - 1][x] == ' '
					|| game->map.grid[y + 1][x] == ' ' || game->map.grid[y][x - 1] == ' '
					|| game->map.grid[y][x + 1] == ' '))
				return (error_msg("map is not closed by walls"));
			x++;
		}
		y++;
	}
	return (1);
}
