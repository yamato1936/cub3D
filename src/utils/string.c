/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:30:29 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/27 13:16:00 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total;
	unsigned char	*mem;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	total = count * size;
	if (total == 0)
		total = 1;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total)
		mem[i++] = 0;
	return (mem);
}

int	has_cub_extension(const char *path)
{
	size_t	len;
	size_t	name_start;

	len = ft_strlen(path);
	name_start = len;
	while (name_start > 0 && path[name_start - 1] != '/')
		name_start--;
	if (len - name_start <= 4)
		return (0);
	return (!ft_strcmp(path + len - 4, ".cub"));
}
