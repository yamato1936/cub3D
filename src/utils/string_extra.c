/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:30:25 by toyamagu          #+#    #+#             */
/*   Updated: 2026/05/24 15:54:26 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	*skip_spaces(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

int	is_empty_line(const char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (*s == '\0');
}

int	is_map_line(const char *s)
{
	s = skip_spaces((char *)s);
	if ((*s == 'N' && s[1] == 'O') || (*s == 'S' && s[1] == 'O'))
		return (0);
	if ((*s == 'W' && s[1] == 'E') || (*s == 'E' && s[1] == 'A'))
		return (0);
	if ((*s == 'F' || *s == 'C') && ft_isspace(s[1]))
		return (0);
	return (*s == '0' || *s == '1' || *s == 'N' || *s == 'S' || *s == 'E'
		|| *s == 'W');
}
