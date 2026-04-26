#include "../../includes/cub3d.h"

int	load_game(t_game *game, const char *path)
{
	if (!parse_file(game, path))
		return (0);
	if (!validate_scene(game))
		return (0);
	if (!init_mlx_game(game))
		return (0);
	if (!load_textures(game))
		return (0);
	game->ready = 1;
	return (1);
}

int	start_game(t_game *game)
{
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, on_close, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, on_key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, on_key_release, game);
	mlx_loop_hook(game->mlx, on_loop, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("usage: ./cub3D <scene.cub>"));
	if (!init_game(&game))
		return (EXIT_FAILURE);
	if (!load_game(&game, argv[1]))
		return (destroy_game(&game), EXIT_FAILURE);
	start_game(&game);
	destroy_game(&game);
	return (EXIT_SUCCESS);
}
