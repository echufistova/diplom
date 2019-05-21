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

int		move_cars(t_map map)
{
	int j;
    t_list_stations	*way;

    j = -1;
    way = map.ways[0];
    map.car.way_size = ft_list_size(way) - 1;
	while (++j < map.station[map.start_station_id].links_amount)
		if (map.station[map.start_station_id].links[j] == map.end_station_id &&
				from_start_to_end(map))
			return (1);
	while (1 <= map.car.way_size)
	{
	    printf("car_mileage: %d - map.km: %d\n", map.car.mileage, map.km);
        if (map.car.mileage > map.km)
        {
            map.car.way = way;
//            cars[j].currnet_index++;
            map.car.way_size = ft_list_size(way) - 1;
            ft_printf("L%d-%s\n", 1,
                      way->name);
            map.km += (int)way->distance_to_next_station;
            way = way->next;
        }
        else
        {
            ft_printf("Беда :(\n");
            break;
        }
	}
	return (1);
}

