/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:14 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:51 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_frame(t_game *game)
{
	game->frame.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->frame.img)
		return (error_msg("failed to create frame image"));
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.line_len, &game->frame.endian);
	game->frame.width = WIN_W;
	game->frame.height = WIN_H;
	if (!game->frame.addr)
		return (error_msg("failed to access frame buffer"));
	return (1);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	tex_pixel(t_tex *tex, int x, int y)
{
	char	*src;

	if (x < 0 || y < 0 || x >= tex->width || y >= tex->height)
		return (0);
	src = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)src);
}

void	clear_frame(t_img *img, t_color top, t_color bottom)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (y < img->height / 2)
				put_pixel(img, x, y, top.value);
			else
				put_pixel(img, x, y, bottom.value);
			x++;
		}
		y++;
	}
}

void	present_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
