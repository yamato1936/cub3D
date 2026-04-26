#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define WIN_W 1024
# define WIN_H 768
# define PLANE_LEN 0.80

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	value;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_tex
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	t_tex	*tex;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
	t_keys		keys;
	double		move_speed;
	double		rot_speed;
	long		last_tick;
	int			ready;
}	t_game;

int		main(int argc, char **argv);
int		init_game(t_game *game);
int		load_game(t_game *game, const char *path);
int		start_game(t_game *game);
int		parse_file(t_game *game, const char *path);
int		validate_scene(t_game *game);
int		parse_element_line(t_game *game, char *line);
int		parse_color_line(t_color *color, char *line);
char	**split_lines(char *text);
int		parse_scene_lines(t_game *game, char **lines);
int		scene_has_all_elements(t_game *game);
int		init_mlx_game(t_game *game);
int		init_frame(t_game *game);
int		load_textures(t_game *game);
void	destroy_game(t_game *game);
int		close_game(t_game *game);
void	render_frame(t_game *game);
void	update_player(t_game *game);
void	rotate_player(t_game *game, double angle);
void	update_timing(t_game *game);
int		is_walkable(t_game *game, double x, double y);
void	put_pixel(t_img *img, int x, int y, int color);
int		tex_pixel(t_tex *tex, int x, int y);
void	clear_frame(t_img *img, t_color top, t_color bottom);
void	present_frame(t_game *game);
void	init_ray(t_game *game, t_ray *ray, int x);
void	init_ray_step(t_game *game, t_ray *ray);
void	run_dda(t_game *game, t_ray *ray);
void	finish_ray(t_game *game, t_ray *ray);
void	prepare_texture(t_game *game, t_ray *ray);
void	draw_column(t_game *game, t_ray *ray, int x);
int		on_key_press(int keycode, t_game *game);
int		on_key_release(int keycode, t_game *game);
int		on_close(t_game *game);
int		on_loop(t_game *game);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		has_cub_extension(const char *path);
int		ft_isspace(int c);
char	*skip_spaces(char *s);
int		is_empty_line(const char *s);
int		is_map_line(const char *s);
void	free_grid(char **grid);
char	**dup_grid(const char **src, int count);
long	timestamp_ms(void);
void	set_color(t_color *color, int r, int g, int b);
int		error_msg(const char *msg);

#endif
