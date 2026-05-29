/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:45 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/29 15:06:38 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	max_width(t_map *map)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) > max)
			max = ft_strlen(map->grid[i]);
		i++;
	}
	return (max);
}

static void	fill_row(char *dst, char *src, size_t width)
{
	size_t	i;

	i = 0;
	while (src[i] && i < width)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < width)
		dst[i++] = ' ';
}

static int	validate_map_dimensions(size_t width, size_t height)
{
	if (width > MAX_MAP_WIDTH)
		return (error_msg("map width exceeds limit"));
	if (height > MAX_MAP_HEIGHT)
		return (error_msg("map height exceeds limit"));
	if (height != 0 && width > SIZE_MAX / height)
		return (error_msg("map dimensions overflow"));
	return (1);
}

static int	normalize_map(t_game *game)
{
	size_t	i;
	size_t	width;
	char	**copy;

	width = max_width(&game->map);
	if (!validate_map_dimensions(width, game->map.height))
		return (0);
	game->map.width = width;
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
	if (!game->map.grid || game->map.height == 0)
		return (error_msg("map is missing"));
	if (!normalize_map(game))
		return (0);
	if (!scan_map_cells(game))
		return (0);
	if (!check_map_closed(game))
		return (0);
	return (1);
}
