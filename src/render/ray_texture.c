/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:29:57 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:18 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_tex	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (&game->we);
	if (ray->side == 0)
		return (&game->ea);
	if (ray->ray_dir_y > 0)
		return (&game->no);
	return (&game->so);
}

static double	hit_position(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		return (game->player.y + ray->perp_dist * ray->ray_dir_y);
	return (game->player.x + ray->perp_dist * ray->ray_dir_x);
}

void	prepare_texture(t_game *game, t_ray *ray)
{
	ray->tex = pick_texture(game, ray);
	ray->wall_x = hit_position(game, ray);
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * ray->tex->width);
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= ray->tex->width)
		ray->tex_x = ray->tex->width - 1;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
}
