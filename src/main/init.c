#include "../../includes/cub3d.h"

int	init_game(t_game *game)
{
	*game = (t_game){0};
	game->floor = (t_color){-1, -1, -1, -1};
	game->ceiling = (t_color){-1, -1, -1, -1};
	update_timing(game);
	return (1);
}
