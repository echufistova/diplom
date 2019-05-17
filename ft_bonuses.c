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

int		bonus_ways(t_farm farm, char **av)
{
	if ((av[1] && av[1][0] == '-' && av[1][1] == 'w' && ft_strlen(av[1]) == 2)
	|| (av[2] && av[2][0] == '-' && av[2][1] == 'w' && ft_strlen(av[2]) == 2)
	|| (av[3] && av[3][0] == '-' && av[3][1] == 'w' && ft_strlen(av[2]) == 2))
	{
		print_ways(farm);
		return (1);
	}
	return (0);
}

int		bonus_lines(t_farm farm, char **av)
{
	if ((av[1] && av[1][0] == '-' && av[1][1] == 'w' && ft_strlen(av[1]) == 2)
	|| (av[2] && av[2][0] == '-' && av[2][1] == 'w' && ft_strlen(av[2]) == 2)
	|| (av[3] && av[3][0] == '-' && av[3][1] == 'w' && ft_strlen(av[2]) == 2))
	{
		ft_printf("Here lines : %d\n", farm.lines);
		return (1);
	}
	return (0);
}

void	the_end(void)
{
	ft_printf("\nIf you want colorful output, enter '-c' after name of file\n");
	ft_printf("If you want to see all possible ways,"
			" enter '-w' after name of file\n");
	ft_printf("If you want to see amount of lines in output,"
			" enter '-l' after name of file\n");
}

int		write_error(char *s)
{
	write(1, "\e[31m", 5);
	ft_printf("%s\n", s);
	write(1, "\e[0m", 4);
	return (0);
}

void	bzero_ways(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->room_amount)
	{
		if (farm->rooms[i].flag != 2)
			farm->rooms[i].flag = 0;
		i++;
	}
}
