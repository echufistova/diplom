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

t_list_stations		*ft_list_station_new(t_station station)
{
	int			i;
    t_list_stations	*res;

	i = 0;
	if (!(res = (t_list_stations*)malloc(sizeof(t_list_stations))))
		return (NULL);
	res->id = station.id;
	res->name = station.name;
	res->links_amount = station.links_amount;
	res->charges.fast_charge = station.charges.fast_charge;
	res->charges.midd_charge = station.charges.midd_charge;
    res->distance_to_next_station = station.distance_to_next_station;
    if (station.links_amount != 0)
	{
		res->links = (int *)malloc(sizeof(int) * station.links_amount);
		while (i < station.links_amount)
		{
			res->links[i] = station.links[i];
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

int				ft_list_station_find(t_list_stations *station_list, int id)
{
    t_list_stations *stations_list;

	stations_list = station_list;
	while (stations_list)
	{
		if (stations_list->id == id)
			return (1);
		stations_list = stations_list->next;
	}
	return (0);
}

int				ft_list_size(t_list_stations *dop)
{
	int			    i;
    t_list_stations *stations_list;

	i = 0;
	stations_list = dop;
	while (stations_list->next)
	{
		stations_list = stations_list->next;
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
