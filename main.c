/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:46:50 by mrio              #+#    #+#             */
/*   Updated: 2026/03/26 19:49:09 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}
int	main(int ac, char *av[])
{
	t_data data;
	if (ac != 2)
		return (error("too many args"), 1);
	if (!parse(av[1], &data))
		return (1);
	return (0);
}