/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:23:08 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 18:45:28 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_valid_name(t_farm farm, const char *name)
{
	t_list_stations	*dop;

	dop = farm.dop;
	if (name[0] == 'L' || name[0] == '#' ||
			(name[0] == '-' && ft_strlen(name) == 1))
		return (write_error("NAME ERROR\n"));
	while (dop->next)
	{
		if (ft_strcmp(dop->name, name) == 0)
			return (write_error("THE SAME ROOM NAME IS PRESENT"));
		dop = dop->next;
	}
	return (1);
}

int		is_valid_map(t_farm farm)
{
	if (farm.ants_amount < 1 || farm.ants_amount > 2147483647)
		return (write_error("NOT GOOD AMOUNT OF ANTS. ERROR"));
	if (farm.start_room_id == -1)
		return (write_error("THERE IS NO START ROOM. ERROR"));
	if (farm.end_room_id == -1)
		return (write_error("THERE IS NO END ROOM. ERROR"));
	if (farm.room_amount < 2)
		return (write_error("NOT ENOUGH ROOMS. ERROR"));
	return (1);
}

int		mb_find_answer(t_farm farm, t_list_stations *dop2, t_list_stations **dop)
{
	if (dop2->id == farm.end_room_id)
	{
		free_list(dop);
		return (1);
	}
	return (0);
}

int		is_answer(t_farm farm)
{
	int			j;
	t_list_stations	*room_list;
	t_list_stations	*dop2;
	t_list_stations	*dop;

	room_list = ft_list_room_new(farm.rooms[farm.start_room_id]);
	dop = room_list;
	dop2 = room_list;
	while (dop2)
	{
		if (mb_find_answer(farm, dop2, &dop))
			return (1);
		j = -1;
		while (++j < dop2->links_amount)
		{
			if (!ft_list_room_find(dop, dop2->links[j]))
			{
				room_list->next = ft_list_room_new(farm.rooms[dop2->links[j]]);
				room_list = room_list->next;
			}
		}
		dop2 = dop2->next;
	}
	free_list(&dop);
	return (write_error("NO WAY TO END :("));
}
