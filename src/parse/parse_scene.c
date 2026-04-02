#include "../../includes/cub3d.h"

static int	store_map(t_game *game, char **lines, int start, int height)
{
	game->map.height = height;
	game->map.grid = dup_grid((const char **)(lines + start), height);
	if (!game->map.grid)
		return (error_msg("failed to allocate map"));
	return (1);
}

static void	register_map_line(int *start, int *height, int index)
{
	if (*start < 0)
		*start = index;
	(*height)++;
}

int	parse_scene_lines(t_game *game, char **lines)
{
	int	i;
	int	start;
	int	height;
	i = 0; start = -1; height = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]) && start >= 0)
			return (error_msg("empty line inside map"));
		if (is_empty_line(lines[i]))
			;
		else if (start < 0 && !is_map_line(lines[i]))
		{
			if (!parse_element_line(game, lines[i]))
				return (0);
		}
		else
			register_map_line(&start, &height, i);
		i++;
	}
	if (start < 0 || !scene_has_all_elements(game))
		return (error_msg("scene is missing mandatory data"));
	return (store_map(game, lines, start, height));
}
