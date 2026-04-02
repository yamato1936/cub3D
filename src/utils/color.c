#include "../../includes/cub3d.h"

void	set_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->value = (r << 16) | (g << 8) | b;
}
