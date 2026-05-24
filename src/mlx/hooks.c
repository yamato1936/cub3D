/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:07 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_key_state(t_keys *keys, int keycode, int value)
{
	if (keycode == XK_w || keycode == XK_W)
		keys->w = value;
	else if (keycode == XK_a || keycode == XK_A)
		keys->a = value;
	else if (keycode == XK_s || keycode == XK_S)
		keys->s = value;
	else if (keycode == XK_d || keycode == XK_D)
		keys->d = value;
	else if (keycode == XK_Left)
		keys->left = value;
	else if (keycode == XK_Right)
		keys->right = value;
}

int	on_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (close_game(game));
	set_key_state(&game->keys, keycode, 1);
	return (0);
}

int	on_key_release(int keycode, t_game *game)
{
	set_key_state(&game->keys, keycode, 0);
	return (0);
}

int	on_close(t_game *game)
{
	return (close_game(game));
}

int	on_loop(t_game *game)
{
	if (!game->ready)
		return (0);
	update_timing(game);
	update_player(game);
	render_frame(game);
	return (0);
}
