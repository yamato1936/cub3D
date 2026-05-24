/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:29:50 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	run_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

void	finish_ray(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = (ray->map_x - game->player.x
				+ (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_dist = (ray->map_y - game->player.y
				+ (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	if (ray->perp_dist < 0.001)
		ray->perp_dist = 0.001;
	ray->line_height = (int)(WIN_H / ray->perp_dist);
	ray->draw_start = WIN_H / 2 - ray->line_height / 2;
	ray->draw_end = WIN_H / 2 + ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}
