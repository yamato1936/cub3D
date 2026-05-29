/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:39 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/29 15:50:12 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	store_map(t_game *game, char **lines, size_t start, size_t height)
{
	if (height > MAX_MAP_HEIGHT)
		return (error_msg("map height exceeds limit"));
	game->map.grid = dup_grid((const char **)(lines + start), height);
	if (!game->map.grid)
		return (error_msg("failed to allocate map"));
	game->map.height = height;
	return (1);
}

static void	trim_trailing_empty_lines(char **lines, size_t start,
	size_t *height)
{
	while (*height > 0 && is_empty_line(lines[start + *height - 1]))
		(*height)--;
}

static int	parse_scene_line(t_game *game, char *line, size_t index,
	size_t state[3])
{
	if (is_empty_line(line) && !state[2])
		return (1);
	if (!state[2] && !is_map_line(line))
		return (parse_element_line(game, line));
	if (!state[2])
	{
		state[0] = index;
		state[2] = 1;
	}
	state[1]++;
	return (1);
}

static int	collect_scene_data(t_game *game, char **lines, size_t state[3])
{
	size_t	i;

	i = 0;
	while (lines[i])
	{
		if (!parse_scene_line(game, lines[i], i, state))
			return (0);
		i++;
	}
	return (1);
}

int	parse_scene_lines(t_game *game, char **lines)
{
	size_t			state[3];

	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	if (!collect_scene_data(game, lines, state))
		return (0);
	if (state[2])
		trim_trailing_empty_lines(lines, state[0], &state[1]);
	if (!state[2] || state[1] == 0 || !scene_has_all_elements(game))
		return (error_msg("scene is missing mandatory data"));
	return (store_map(game, lines, state[0], state[1]));
}
