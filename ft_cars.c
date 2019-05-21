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

t_car	*create_cars(int cars_amount)
{
	int		i;
	t_car	*cars;

	i = 0;
	cars = (t_car*)malloc(sizeof(t_car) * cars_amount);
	while (i < cars_amount)
	{
		cars[i].number = i + 1;
		cars[i].way = NULL;
		cars[i].way_size = -1;
		cars[i].currnet_index = 0;
		i++;
	}
	return (cars);
}

int		all_cars_got_end(t_car *cars, int cars_amount)
{
	int i;

	i = -1;
	while (++i < cars_amount)
	{
		if (cars[i].currnet_index <= cars[i].way_size)
			return (0);
	}
	return (1);
}

int		get_cars(t_map map, t_car *cars, int current_cars_number)
{
	int	i;
	int j;
	int check_exp;

	i = -1;
	while (++i < map.ways_amount)
	{
		check_exp = 0;
		j = -1;
		while (i != 0 && ++j < i)
			check_exp += map.ways[i]->size - map.ways[j]->size;
		if (map.cars_amount - current_cars_number >= check_exp)
		{
			cars[current_cars_number - 1].way = map.ways[i];
			cars[current_cars_number - 1].way_size =
				ft_list_size(map.ways[i]) - 1;
			cars[current_cars_number - 1].currnet_index++;
			current_cars_number++;
		}
	}
	return (current_cars_number);
}

int		from_start_to_end(t_map map, t_car *cars)
{
	int i;

	i = -1;
	while (++i < map.cars_amount)
	{
		ft_printf("L%d-%s ", cars[i].number,
				  map.station[map.start_station_id].name);
		ft_printf("L%d-%s ", cars[i].number,
				map.station[map.end_station_id].name);
	}
	ft_printf("\n");
	return (1);
}

int		move_cars(t_map map, t_car *cars)
{
	int j;
    t_list_stations	*way;

    j = -1;
    way = map.ways[0];
    cars[0].way_size = ft_list_size(way) - 1;
	while (++j < map.station[map.start_station_id].links_amount)
		if (map.station[map.start_station_id].links[j] == map.end_station_id &&
				from_start_to_end(map, cars))
			return (1);
	while (1 <= cars[0].way_size)
	{
//        if (cars[0].mileage < map.km)
//        {
            cars[0].way = way;
            cars[j].currnet_index++;
            cars[0].way_size = ft_list_size(way) - 1;
            ft_printf("L%d-%s\n", 1,
                      way->name);
            way = way->next;
//            map.km += map.station
//        }
	}
	return (1);
}

