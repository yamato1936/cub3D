/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:46:47 by mrio              #+#    #+#             */
/*   Updated: 2026/03/26 20:28:53 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse(char *map_name, t_data *data)
{
	int fd;
	char *line;
	if (ft_strlen(map_name) < 6 || ft_strcmp(map_name + ft_strlen(map_name) - 4,
			".cub") != 0)
		return (error("file name must have .cub"), 1);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (error("file is broken"), 1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	return (0);
}