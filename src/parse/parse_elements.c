/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:31 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*dup_trimmed(char *line)
{
	int		len;
	char	*copy;

	line = skip_spaces(line);
	len = ft_strlen(line);
	while (len > 0 && ft_isspace(line[len - 1]))
		len--;
	if (len == 0)
		return (NULL);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	copy[len] = '\0';
	while (len-- > 0)
		copy[len] = line[len];
	return (copy);
}

static int	set_texture_line(char **slot, char *line, const char *name)
{
	if (*slot)
		return (error_msg(name));
	*slot = dup_trimmed(line);
	if (!*slot)
		return (error_msg("invalid texture path"));
	return (1);
}

static int	parse_texture_line(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO", 2) && ft_isspace(line[2]))
		return (set_texture_line(&game->no.path, line + 2, "duplicate NO"));
	if (!ft_strncmp(line, "SO", 2) && ft_isspace(line[2]))
		return (set_texture_line(&game->so.path, line + 2, "duplicate SO"));
	if (!ft_strncmp(line, "WE", 2) && ft_isspace(line[2]))
		return (set_texture_line(&game->we.path, line + 2, "duplicate WE"));
	if (!ft_strncmp(line, "EA", 2) && ft_isspace(line[2]))
		return (set_texture_line(&game->ea.path, line + 2, "duplicate EA"));
	return (-1);
}

int	parse_element_line(t_game *game, char *line)
{
	int	status;

	line = skip_spaces(line);
	status = parse_texture_line(game, line);
	if (status >= 0)
		return (status);
	if (line[0] == 'F' && ft_isspace(line[1]))
		return (parse_color_line(&game->floor, line + 1));
	if (line[0] == 'C' && ft_isspace(line[1]))
		return (parse_color_line(&game->ceiling, line + 1));
	return (error_msg("invalid element line"));
}

int	scene_has_all_elements(t_game *game)
{
	return (game->no.path && game->so.path && game->we.path
		&& game->ea.path && game->floor.r >= 0 && game->ceiling.r >= 0);
}
