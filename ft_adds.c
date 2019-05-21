/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:22:04 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/06 16:31:47 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_map *map, char *line, int i)
{
	int		j;
	t_station	dop_rm;

	j = 0;
	if (map->station[i].links_amount > 0)
	{
		dop_rm.name = NULL;
		dop_rm.flag = 0;
		dop_rm.links_amount = map->station[i].links_amount;
		dop_rm.links = (int*)malloc(sizeof(int) * map->station[i].links_amount);
		j = -1;
		while (++j < map->station[i].links_amount)
			dop_rm.links[j] = map->station[i].links[j];
		free(map->station[i].links);
		map->station[i].links = (int*)malloc(sizeof(int) *
				(map->station[i].links_amount + 1));
		j = -1;
		while (++j < map->station[i].links_amount)
			map->station[i].links[j] = dop_rm.links[j];
		free(dop_rm.links);
	}
	else
		map->station[i].links = (int*)malloc(sizeof(int));
	map->station[i].links[j] = is_car(*map, line);
	map->station[i].links_amount++;
}

int		find_link_dop(t_map map, char *dop, char **name, t_point ij)
{
	while (++ij.y < map.station[ij.x].links_amount)
		if (map.station[ij.x].links[ij.y] == is_car(map, dop))
		{
			ft_strdel(name);
			return (0);
		}
	return (1);
}

int		find_link(t_map *map, char **line, int k)
{
	t_point	ij;
	char	*dop;
	char	*name;

	ij.y = -1;
	dop = ft_strchr(*line, '-');
	name = ft_strsub(*line, 0, dop - *line);
	ij.x = is_car(*map, name);
	if (ij.x > -1 && is_car(*map, ++dop) > -1 && ij.x != is_car(*map, dop))
	{
		if (!find_link_dop(*map, dop, &name, ij))
			return (0);
		add_link(map, dop, ij.x);
		if (++k < 2)
		{
			dop = ft_strcat(ft_strcat(dop, "-"), name);
			find_link(map, &dop, k);
		}
		ft_strdel(&name);
		return (1);
	}
	ft_strdel(&name);
	ft_strdel(line);
	return (0);
}

int		is_car(t_map map, char *name)
{
	int i;

	i = 0;
	if (name)
	{
		while (i < map.car_amount)
		{
			if (ft_strcmp(map.station[i].name, name) == 0)
				return (i);
			i++;
		}
	}
	return (-1);
}

void	make_stations(t_map *map)
{
	int			    i;
	t_list_stations	*dop2;

	i = 0;
	map->station = (t_station*)malloc(sizeof(t_station) * map->car_amount);
	dop2 = map->dop;
	map->dop->size = ft_list_size(map->dop);
	while (dop2->next)
	{
		map->station[i].id = dop2->id;
		map->station[i].name = ft_strdup(dop2->name);
		map->station[i].charges.midd_charge = dop2->charges.midd_charge;
		map->station[i].charges.fast_charge = dop2->charges.fast_charge;
		map->station[i].distance_to_next_station = dop2->distance_to_next_station;
		map->station[i].links_amount = 0;
		map->station[i].links = NULL;
		dop2 = dop2->next;
		i++;
	}
}
