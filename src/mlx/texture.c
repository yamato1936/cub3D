/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:21 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:54 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_texture(t_game *game, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (error_msg("failed to load an xpm texture"));
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
		return (error_msg("failed to access texture data"));
	return (1);
}

int	load_textures(t_game *game)
{
	if (!load_texture(game, &game->no))
		return (0);
	if (!load_texture(game, &game->so))
		return (0);
	if (!load_texture(game, &game->we))
		return (0);
	if (!load_texture(game, &game->ea))
		return (0);
	return (1);
}
