/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:45 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:52:19 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	max_width(t_map *map)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) > max)
			max = ft_strlen(map->grid[i]);
		i++;
	}
	return (max);
}

static void	fill_row(char *dst, char *src, int width)
{
	int	i;

	i = 0;
	while (src[i] && i < width)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < width)
		dst[i++] = ' ';
}

static int	normalize_map(t_game *game)
{
	int		i;
	char	**copy;

	game->map.width = max_width(&game->map);
	copy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!copy)
		return (error_msg("failed to normalize map"));
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!copy[i])
			return (free_grid(copy), error_msg("failed to normalize map"));
		fill_row(copy[i], game->map.grid[i], game->map.width);
		i++;
	}
	free_grid(game->map.grid);
	game->map.grid = copy;
	return (1);
}

int	validate_scene(t_game *game)
{
	if (!game->map.grid || game->map.height <= 0)
		return (error_msg("map is missing"));
	if (!normalize_map(game))
		return (0);
	if (!scan_map_cells(game))
		return (0);
	if (!check_map_closed(game))
		return (0);
	return (1);
}
