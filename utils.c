/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:26:22 by mrio              #+#    #+#             */
/*   Updated: 2026/03/26 19:43:42 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int ft_strlen(char *str)
{
    int count;
    count=0;
    while(str[count])
    {
        count++;
    }
    return count;
}

int ft_strcmp(char *s1,char *s2)
{
    int i;
    i=0;

    while(s1[i]==s2[i]&&s1[i]&&s2[i])
        i++;
    return(s1[i]-s2[i]);
}