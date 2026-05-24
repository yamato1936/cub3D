/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:30:01 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:19 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_columns(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(game, &ray, x);
		init_ray_step(game, &ray);
		run_dda(game, &ray);
		finish_ray(game, &ray);
		prepare_texture(game, &ray);
		draw_column(game, &ray, x++);
	}
}

void	render_frame(t_game *game)
{
	clear_frame(&game->frame, game->ceiling, game->floor);
	render_columns(game);
	present_frame(game);
}
