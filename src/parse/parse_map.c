/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:36 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:51:35 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	count_lines(char *text)
{
	size_t	i;
	size_t	count;

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

static char	*dup_line(char *start, size_t len)
{
	char	*line;
	size_t	i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = start[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static int	add_line(char **lines, size_t *row, char *start, size_t len)
{
	lines[*row] = dup_line(start, len);
	if (!lines[*row])
		return (0);
	(*row)++;
	return (1);
}

static int	fill_lines(char **lines, char *text)
{
	size_t	i;
	size_t	row;
	size_t	start;

	i = 0;
	row = 0;
	start = 0;
	while (text[i])
	{
		if (text[i] == '\n')
		{
			if (!add_line(lines, &row, text + start, i - start))
				return (0);
		}
		if (text[i++] == '\n')
			start = i;
	}
	if (i > start)
	{
		if (!add_line(lines, &row, text + start, i - start))
			return (0);
	}
	lines[row] = NULL;
	return (1);
}

char	**split_lines(char *text)
{
	size_t	count;
	char	**lines;

	count = count_lines(text);
	lines = ft_calloc(count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	if (!fill_lines(lines, text))
		return (free_grid(lines), NULL);
	return (lines);
}
