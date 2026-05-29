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

static char	*join_chunk(char *text, size_t size, char *buf, ssize_t len)
{
	char	*new_text;
	size_t	i;
	size_t	chunk_len;

	chunk_len = (size_t)len;
	if (size > SIZE_MAX - chunk_len - 1)
		return (free(text), NULL);
	new_text = malloc(size + chunk_len + 1);
	if (!new_text)
		return (free(text), NULL);
	i = 0;
	while (i < size)
	{
		new_text[i] = text[i];
		i++;
	}
	i = 0;
	while (i < chunk_len)
	{
		new_text[size + i] = buf[i];
		i++;
	}
	new_text[size + chunk_len] = '\0';
	return (free(text), new_text);
}

static char	*read_scene(int fd)
{
	char	buf[1024];
	char	*text;
	size_t	size;
	ssize_t	len;

	text = ft_strdup("");
	size = 0;
	while (text)
	{
		len = read(fd, buf, sizeof(buf));
		if (len < 0)
			return (free(text), NULL);
		if (len == 0)
			break ;
		text = join_chunk(text, size, buf, len);
		if (!text)
			return (NULL);
		size += (size_t)len;
	}
	return (text);
}

static int	is_scene_too_large(const char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (0);
	if (st.st_size < 0)
		return (0);
	return (st.st_size > (off_t)MAX_CUB_BYTES);
}

static char	*load_scene(const char *path)
{
	int		fd;
	char	*text;

	if (!has_cub_extension(path))
		return (error_msg("scene file must use the .cub extension"), NULL);
	if (is_scene_too_large(path))
		return (error_msg("scene file exceeds size limit"), NULL);
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
