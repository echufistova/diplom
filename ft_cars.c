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
				  map.rooms[map.start_room_id].name);
		ft_printf("L%d-%s ", cars[i].number,
				map.rooms[map.end_room_id].name);
	}
	ft_printf("\n");
	return (1);
}

int		move_cars(t_map map, t_car *cars)
{
	int j;
	int counter;
	int current_cars_number;

	counter = 0;
	current_cars_number = 1;
	j = -1;
	while (++j < map.rooms[map.start_room_id].links_amount)
		if (map.rooms[map.start_room_id].links[j] == map.end_room_id &&
				from_start_to_end(map, cars))
			return (1);
    ft_printf("L%d-%s\n", 1,
              map.rooms[map.start_room_id].name);
	while (current_cars_number <= map.cars_amount ||
			!all_cars_got_end(cars, map.cars_amount))
	{
		if (current_cars_number <= map.cars_amount)
			current_cars_number = get_cars(map, cars, current_cars_number);
		print_cars_movings(cars, current_cars_number - 1);
		counter++;
		j = -1;
		while (++j < current_cars_number - 1)
			cars[j].currnet_index++;
	}
	return (counter);
}
