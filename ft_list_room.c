/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:24:33 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 18:49:04 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_stations		*ft_list_room_new(t_station room)
{
	int			i;
    t_list_stations	*res;

	i = 0;
	if (!(res = (t_list_stations*)malloc(sizeof(t_list_stations))))
		return (NULL);
	res->id = room.id;
	res->name = room.name;
	res->links_amount = room.links_amount;
	if (room.links_amount != 0)
	{
		res->links = (int *)malloc(sizeof(int) * room.links_amount);
		while (i < room.links_amount)
		{
			res->links[i] = room.links[i];
			i++;
		}
	}
	else
		res->links = NULL;
	res->next = NULL;
	res->prev = NULL;
	res->size = 1;
	return (res);
}

int				ft_list_room_find(t_list_stations *dop, int id)
{
    t_list_stations *room_list;

	room_list = dop;
	while (room_list)
	{
		if (room_list->id == id)
			return (1);
		room_list = room_list->next;
	}
	return (0);
}

int				ft_list_size(t_list_stations *dop)
{
	int			    i;
    t_list_stations *room_list;

	i = 0;
	room_list = dop;
	while (room_list)
	{
		room_list = room_list->next;
		i++;
	}
	return (i);
}

void			free_list(t_list_stations **dop)
{
    t_list_stations *tmp;

	while (*dop)
	{
		tmp = (*dop)->next;
		free((*dop)->links);
		free(*dop);
		*dop = tmp;
	}
}

void			print_cars_movings(t_car *cars, int cars_amount)
{
	int			    i;
	int			    j;
    t_list_stations	*tmp_way;

	i = -1;
	while (++i < cars_amount)
	{
		if (cars[i].currnet_index > cars[i].way_size)
			continue;
		tmp_way = cars[i].way;
		j = -1;
		while (++j < cars[i].currnet_index)
			tmp_way = tmp_way->next;
		if (cars[i].currnet_index != 0)
		{
			ft_printf("L%d-%s ", cars[i].number, tmp_way->name);
			write(1, "\e[0m", 4);
		}
	}
	ft_printf("\n");
}
