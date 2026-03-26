/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:54 by mrio              #+#    #+#             */
/*   Updated: 2025/07/27 01:46:08 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_and_init(int fd, char **save)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!*save)
	{
		*save = ft_strdup("");
		if (!*save)
			return (0);
	}
	return (1);
}

static int	read_buff(int fd, char **save)
{
	char	*buff;
	char	*tmp;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes == -1)
		return (free(buff), -1);
	if (bytes == 0)
		return (free(buff), 0);
	buff[bytes] = '\0';
	tmp = ft_strjoin(*save, buff);
	free(*save);
	free(buff);
	*save = tmp;
	if (!*save)
		return (-1);
	return (1);
}

static char	*get_last(char **save)
{
	char	*line;

	if (*save && **save)
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (line);
	}
	free(*save);
	*save = NULL;
	return (NULL);
}

static char	*split_line(char **save, char *pos)
{
	char	*line;
	char	*tmp;

	*pos = '\0';
	line = ft_strjoin(*save, "\n");
	if (!line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = ft_strdup(pos + 1);
	free(*save);
	*save = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*pos;
	int			result;

	if (!(check_and_init(fd, &save)))
		return (NULL);
	pos = ft_strchr(save, '\n');
	while (!pos)
	{
		result = read_buff(fd, &save);
		if (result == -1)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		if (result == 0)
			return (get_last(&save));
		pos = ft_strchr(save, '\n');
	}
	return (split_line(&save, pos));
}
