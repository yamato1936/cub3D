/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:46:14 by mrio              #+#    #+#             */
/*   Updated: 2026/03/26 20:01:59 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
typedef struct s_data
{
}		t_data;
int		ft_strlen(char *str);
int		parse(char *map_name, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	error(char *str);
#endif