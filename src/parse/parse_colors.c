/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toyamagu <toyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:28:26 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:21 by toyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_number(char **line, int *value)
{
	int	number;

	number = 0;
	if (**line < '0' || **line > '9')
		return (0);
	while (**line >= '0' && **line <= '9')
	{
		number = number * 10 + (**line - '0');
		(*line)++;
	}
	if (number > 255)
		return (0);
	*value = number;
	return (1);
}

static int	parse_comma(char **line)
{
	*line = skip_spaces(*line);
	if (**line != ',')
		return (0);
	(*line)++;
	*line = skip_spaces(*line);
	return (1);
}

static int	parse_rgb(char *line, int rgb[3])
{
	line = skip_spaces(line);
	if (!parse_number(&line, &rgb[0]) || !parse_comma(&line))
		return (0);
	if (!parse_number(&line, &rgb[1]) || !parse_comma(&line))
		return (0);
	if (!parse_number(&line, &rgb[2]))
		return (0);
	return (*skip_spaces(line) == '\0');
}

int	parse_color_line(t_color *color, char *line)
{
	int	rgb[3];

	if (color->r >= 0)
		return (error_msg("duplicate color"));
	if (!parse_rgb(line, rgb))
		return (error_msg("invalid color"));
	set_color(color, rgb[0], rgb[1], rgb[2]);
	return (1);
}
