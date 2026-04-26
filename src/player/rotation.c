#include "../../includes/cub3d.h"

static void	rotate_vec(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

void	rotate_player(t_game *game, double angle)
{
	rotate_vec(&game->player.dir_x, &game->player.dir_y, angle);
	rotate_vec(&game->player.plane_x, &game->player.plane_y, angle);
}
