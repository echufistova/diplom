/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:26:31 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 19:23:37 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_way_dop(t_map *map, t_list_stations **new)
{
	map->ways_amount++;
	free_list(new);
}

void	get_way(t_map *map, t_list_stations *way, int flag)
{
	t_list_stations *rm;
	t_list_stations *dop;
	t_list_stations *new;

	bzero_ways(map);
	map->ways[map->ways_amount] = ft_list_station_new(map->station[
                                                              map->start_station_id]);
	dop = map->ways[map->ways_amount];
	rm = way->prev;
	while (rm->id != map->end_station_id)
	{
		map->ways[map->ways_amount]->next = ft_list_station_new(map->station
                                                                [rm->id]);
		map->ways[map->ways_amount] = map->ways[map->ways_amount]->next;
		map->station[rm->id].flag = 2;
		rm = rm->prev;
	}
	new = rm;
	map->ways[map->ways_amount]->next = ft_list_station_new(map->station[
                                                                    rm->id]);
	map->ways[map->ways_amount] = dop;
	map->ways[map->ways_amount]->size = ft_list_size(map->ways[
			map->ways_amount]) - 1;
	get_way_dop(map, &new);
	find_ways(map, flag);
}

int		find_ways_dop(t_map *map, t_list_stations **way,
						 t_list_stations *dop2, t_point i)
{
	if ((*way)->id != map->end_station_id && (*way)->id != -1)
		map->station[(*way)->id].flag = 1;
	if ((*way)->links_amount == 1 && (*way)->links[0] ==
						map->start_station_id)
	{
		(*way)->next = ft_list_station_new(map->station[dop2->links[i.x]]);
		(*way) = (*way)->next;
		(*way)->prev = dop2;
		get_way(map, (*way), 1);
		return (0);
	}
	if (dop2->links[i.x] != map->end_station_id)
	{
		(*way)->next = ft_list_station_new(map->station[dop2->links[i.x]]);
		(*way) = (*way)->next;
		(*way)->prev = dop2;
		if ((*way)->id == map->start_station_id)
		{
			get_way(map, (*way), i.y);
			return (0);
		}
	}
	return (1);
}

void	find_ways(t_map *map, int flag)
{
	t_point			i;
	t_list_stations	*way;
	t_list_stations	*dop2;
	t_list_stations	*dop;

	way = ft_list_station_new(map->station[map->end_station_id]);
	dop = way;
	dop2 = way;
	i.y = flag;
	while (dop2)
	{
		if (flag == 1)
			break ;
		i.x = -1;
		while (++i.x < dop2->links_amount)
		{
			if (map->station[dop2->links[i.x]].flag != 1 && map->station[
		dop2->links[i.x]].flag != 2 && !find_ways_dop(map, &way, dop2, i))
				return ;
		}
		dop2 = dop2->next;
	}
	free_list(&dop);
	bzero_ways(map);
}

void	print_ways(t_map map)
{
	int			i;
	t_list_stations	*ways;

	i = 0;
	ft_printf("Amount of ways: %d\n", map.ways_amount);
	while (i < map.ways_amount)
	{
		ways = map.ways[i];
		ft_printf("%d) %d : ", i + 1, ways->size);
		while (ways)
		{
			ft_printf("%s -> ", ways->name);
			if (ways->next)
				ways = ways->next;
			else
				break ;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
