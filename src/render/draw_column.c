#include "../../includes/cub3d.h"

static int	tex_y_at(t_tex *tex, double tex_pos)
{
	int	tex_y;

	tex_y = (int)tex_pos;
	if (tex_y < 0)
		return (0);
	if (tex_y >= tex->height)
		return (tex->height - 1);
	return (tex_y);
}

static void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = (double)ray->tex->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = tex_y_at(ray->tex, tex_pos);
		put_pixel(&game->frame, x, y, tex_pixel(ray->tex, ray->tex_x, tex_y));
		tex_pos += step;
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	draw_wall(game, ray, x);
}
