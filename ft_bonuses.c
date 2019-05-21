/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonuses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@43.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:44:16 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/06 20:38:40 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		write_error(char *s)
{
	write(1, "\e[31m", 5);
	ft_printf("%s\n", s);
	write(1, "\e[0m", 4);
	return (0);
}

void	bzero_ways(t_map *farm)
{
	int i;

	i = 0;
	while (i < farm->car_amount)
	{
		if (farm->station[i].flag != 2)
			farm->station[i].flag = 0;
		i++;
	}
}
