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

int		move_cars(t_map *map)
{
	int j;
    t_list_stations	*way;

    j = -1;
    print_ways(*map);
    way = map->ways[0];
    map->car.way_size = ft_list_size(way) - 1;
	while (++j < map->station[map->start_station_id].links_amount) {
        if (map->station[map->start_station_id].links[j] == map->end_station_id &&
            from_start_to_end(*map))
            return (1);
    }
 	while (1 <= map->car.way_size) {
        map->car.way_size = ft_list_size(way) - 1;
	    printf("\ncar_mileage: %d - map.km: %d\n\n", map->car.mileage, map->km);
        ft_printf("we are here : %s\n", way->name);
        if (map->car.way_size - 1 >= 1 && map->km + (int)way->next->distance_to_next_station < map->car.mileage)
        {
            map->car.way = way;
            map->car.way_size = ft_list_size(way) - 1;
            ft_printf("%s is in %s\n", map->car.name, way->name);
            ft_printf("km: %d ", (int)way->distance_to_next_station );
            map->km += (int)(way->distance_to_next_station);
            printf("time: %f\n", (way->distance_to_next_station/100));
            map->time += way->distance_to_next_station / (float)100;
            way = way->next;
            printf("next is %s in %f km\n",  way->name, way->distance_to_next_station);
        }
        else
        {
            map->time += (way->charges.fast_charge == 1) ? map->car.time_fast_charge : map->car.time_midd_charge;
            way = way->next;
            map->km = 0;
//            break;
        }
	}
	printf("whole time: %f \n", map->time);
	return (1);
}

