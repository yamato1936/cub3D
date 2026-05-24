/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:36 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_lines(char *text)
{
	int	i;
	int	count;

	if (!text[0])
		return (0);
	i = 0;
	count = 1;
	while (text[i])
	{
		if (text[i] == '\n' && text[i + 1])
			count++;
		i++;
	}
	return (count);
}

static char	*dup_line(char *start, int len)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = start[i];
	line[len] = '\0';
	return (line);
}

static int	fill_lines(char **lines, char *text)
{
	int	i;
	int	row;
	int	start;

	i = 0;
	row = 0;
	start = 0;
	while (text[i])
	{
		if (text[i] == '\n' && !((lines[row++] = dup_line(text + start, i - start))))
			return (0);
		if (text[i++] == '\n')
			start = i;
	}
	if (i > start && !((lines[row++] = dup_line(text + start, i - start))))
		return (0);
	lines[row] = NULL;
	return (1);
}

char	**split_lines(char *text)
{
	int		count;
	char	**lines;

	count = count_lines(text);
	lines = ft_calloc(count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	if (!fill_lines(lines, text))
		return (free_grid(lines), NULL);
	return (lines);
}
