/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:34 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:51:33 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*join_chunk(char *text, int size, char *buf, int len)
{
	char	*new_text;
	int		i;

	new_text = malloc(size + len + 1);
	if (!new_text)
		return (free(text), NULL);
	i = -1;
	while (++i < size)
		new_text[i] = text[i];
	i = -1;
	while (++i < len)
		new_text[size + i] = buf[i];
	new_text[size + len] = '\0';
	return (free(text), new_text);
}

static char	*read_scene(int fd)
{
	char	buf[1024];
	char	*text;
	int		size;
	int		len;

	text = ft_strdup("");
	size = 0;
	len = 1;
	while (text && len > 0)
	{
		len = read(fd, buf, sizeof(buf));
		if (len < 0)
			return (free(text), NULL);
		text = join_chunk(text, size, buf, len);
		size += len;
	}
	return (text);
}

static char	*load_scene(const char *path)
{
	int		fd;
	char	*text;

	if (!has_cub_extension(path))
		return (error_msg("scene file must use the .cub extension"), NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg("could not open scene file"), NULL);
	text = read_scene(fd);
	close(fd);
	if (!text)
		return (error_msg("failed to read scene file"), NULL);
	return (text);
}

int	parse_file(t_game *game, const char *path)
{
	char	*text;
	char	**lines;
	int		ok;

	text = load_scene(path);
	if (!text)
		return (0);
	lines = split_lines(text);
	free(text);
	if (!lines)
		return (error_msg("failed to split scene file"));
	ok = parse_scene_lines(game, lines);
	free_grid(lines);
	return (ok);
}
