/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:18 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (!game->win)
		return (error_msg("failed to create window"));
	return (1);
}

int	init_mlx_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("failed to initialize mlx"));
	if (!init_window(game))
		return (0);
	if (!init_frame(game))
		return (0);
	return (1);
}
