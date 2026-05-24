NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx-linux
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -l:libXext.so.6 -lX11 -lm
OBJ_DIR = .objs

SRC = src/main/main.c \
	src/main/init.c \
	src/main/cleanup.c \
	src/parse/parse_file.c \
	src/parse/parse_elements.c \
	src/parse/parse_colors.c \
	src/parse/parse_map.c \
	src/parse/parse_scene.c \
	src/parse/validate_map.c \
	src/parse/validate_cells.c \
	src/parse/validate_closed.c \
	src/render/render_frame.c \
	src/render/ray_setup.c \
	src/render/ray_dda.c \
	src/render/ray_texture.c \
	src/render/draw_column.c \
	src/player/movement.c \
	src/player/rotation.c \
	src/player/collision.c \
	src/mlx/mlx_init.c \
	src/mlx/image.c \
	src/mlx/hooks.c \
	src/mlx/texture.c \
	src/utils/error.c \
	src/utils/string.c \
	src/utils/string_extra.c \
	src/utils/memory.c \
	src/utils/time.c \
	src/utils/color.c

OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC=. all

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC=. clean

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
