/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:27:52 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:35 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_tex(t_game *game, t_tex *tex)
{
	if (tex->img && game->mlx)
		mlx_destroy_image(game->mlx, tex->img);
	free(tex->path);
	*tex = (t_tex){0};
}

static void	destroy_frame(t_game *game)
{
	if (!game->frame.img || !game->mlx)
		return ;
	mlx_destroy_image(game->mlx, game->frame.img);
	game->frame = (t_img){0};
}

static void	destroy_window(t_game *game)
{
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	game->win = NULL;
}

void	destroy_game(t_game *game)
{
	destroy_tex(game, &game->no);
	destroy_tex(game, &game->so);
	destroy_tex(game, &game->we);
	destroy_tex(game, &game->ea);
	destroy_frame(game);
	destroy_window(game);
	free_grid(game->map.grid);
	game->map.grid = NULL;
}

int	close_game(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
