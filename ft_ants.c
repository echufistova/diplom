/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:22:36 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 18:14:40 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_car	*create_ants(int ants_amount)
{
	int		i;
	t_car	*ants;

	i = 0;
	ants = (t_car*)malloc(sizeof(t_car) * ants_amount);
	while (i < ants_amount)
	{
		ants[i].number = i + 1;
		ants[i].way = NULL;
		ants[i].way_size = -1;
		ants[i].currnet_index = 0;
		i++;
	}
	return (ants);
}

int		all_ants_got_end(t_car *ants, int ants_amount)
{
	int i;

	i = -1;
	while (++i < ants_amount)
	{
		if (ants[i].currnet_index <= ants[i].way_size)
			return (0);
	}
	return (1);
}

int		get_ants(t_farm farm, t_car *ants, int current_ants_number)
{
	int	i;
	int j;
	int check_exp;

	i = -1;
	while (++i < farm.ways_amount)
	{
		check_exp = 0;
		j = -1;
		while (i != 0 && ++j < i)
			check_exp += farm.ways[i]->size - farm.ways[j]->size;
		if (farm.ants_amount - current_ants_number >= check_exp)
		{
			ants[current_ants_number - 1].way = farm.ways[i];
			ants[current_ants_number - 1].way_size =
				ft_list_size(farm.ways[i]) - 1;
			ants[current_ants_number - 1].currnet_index++;
			current_ants_number++;
		}
	}
	return (current_ants_number);
}

int		from_start_to_end(t_farm farm, t_car *ants)
{
	int i;

	i = -1;
	while (++i < farm.ants_amount)
	{

//		ft_printf("L%d-%s ", ants[i].number,
//				  farm.rooms[farm.start_room_id].name);
		ft_printf("L%d-%s ", ants[i].number,
				farm.rooms[farm.end_room_id].name);
	}
	ft_printf("\n");
	return (1);
}

int		move_ants(t_farm farm, t_car *ants)
{
	int j;
	int counter;
	int current_ants_number;

	counter = 0;
	current_ants_number = 1;
	j = -1;
	while (++j < farm.rooms[farm.start_room_id].links_amount)
		if (farm.rooms[farm.start_room_id].links[j] == farm.end_room_id &&
				from_start_to_end(farm, ants))
			return (1);
	while (current_ants_number <= farm.ants_amount ||
			!all_ants_got_end(ants, farm.ants_amount))
	{
		if (current_ants_number <= farm.ants_amount)
			current_ants_number = get_ants(farm, ants, current_ants_number);
		print_ants_movings(ants, current_ants_number - 1);
		counter++;
		j = -1;
		while (++j < current_ants_number - 1)
			ants[j].currnet_index++;
	}
	return (counter);
}
