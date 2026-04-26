#include "../../includes/cub3d.h"

static void	move_axis(t_game *game, double next_x, double next_y)
{
	if (is_walkable(game, next_x, game->player.y))
		game->player.x = next_x;
	if (is_walkable(game, game->player.x, next_y))
		game->player.y = next_y;
}

static void	move_forward_back(t_game *game, int dir)
{
	double	next_x;
	double	next_y;

	next_x = game->player.x + game->player.dir_x * game->move_speed * dir;
	next_y = game->player.y + game->player.dir_y * game->move_speed * dir;
	move_axis(game, next_x, next_y);
}

static void	move_strafe(t_game *game, int dir)
{
	double	next_x;
	double	next_y;

	next_x = game->player.x - game->player.dir_y * game->move_speed * dir;
	next_y = game->player.y + game->player.dir_x * game->move_speed * dir;
	move_axis(game, next_x, next_y);
}

void	update_player(t_game *game)
{
	if (game->keys.w)
		move_forward_back(game, 1);
	if (game->keys.s)
		move_forward_back(game, -1);
	if (game->keys.a)
		move_strafe(game, -1);
	if (game->keys.d)
		move_strafe(game, 1);
	if (game->keys.left)
		rotate_player(game, -game->rot_speed);
	if (game->keys.right)
		rotate_player(game, game->rot_speed);
}
