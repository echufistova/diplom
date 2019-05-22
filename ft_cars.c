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

int		from_start_to_end(t_map map)
{
	ft_printf("L%d-%s ", map.car.number,
				  map.station[map.start_station_id].name);
	ft_printf("L%d-%s\n", map.car.number,
				map.station[map.end_station_id].name);
	return (1);
}

int way_to_fast_charge(t_map *map, t_list_stations **way)
{
    t_list_stations *tmp;
    float dop_mileage;
    float dop_time;

    tmp = (*way);
    dop_mileage = 0;
    dop_time = 0;
    while (tmp) {
        if (map->mileage + tmp->distance_to_next_station < map->car.mileage) {
            if (tmp->charges.fast_charge)
            {
                (*way) = tmp;
                dop_mileage = map->km;
                dop_time = map->time;
            }
            map->km += tmp->distance_to_next_station;
            map->mileage += tmp->distance_to_next_station;
        } else {
            map->mileage = 0;
            map->km = dop_mileage + (*way)->distance_to_next_station;
            map->time = dop_time;
            map->time += ((*way)->charges.fast_charge == 1) ?
                    map->car.time_fast_charge : map->car.time_midd_charge;
            printf("Заїхали на зарядну станцію %s, тому що проїхали вже %f кілометрів\n\n", (*way)->name, map->km);
            tmp = (*way);
        }
        map->time += (*way)->distance_to_next_station / (float)100;
        tmp = tmp->next;
    }
    return (0);
}

int		move_cars(t_map *map)
{
    int j;
    t_list_stations	*way;

    j = -1;
    way = map->ways[0];
    map->car.way_size = ft_list_size(way) - 1;
    while (++j < map->station[map->start_station_id].links_amount) {
        if (map->station[map->start_station_id].links[j] == map->end_station_id &&
            from_start_to_end(*map))
            return (1);
    }
    way_to_fast_charge(map, &way);
    printf("Доїхали до пункту призначення. Проїхали %f кілометрів за %f годин.\n",  map->km, map->time);
    return (1);
}