/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:24:19 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/06 19:25:37 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init(t_map *map, char **av)
{

    if (ft_atoi(av[1]) == 1)
        map->car = nissan_leaf;
    else if (ft_atoi(av[1]) == 2)
        map->car = bmw_i3;
    else if (ft_atoi(av[1]) == 3)
        map->car = tesla_model_s;
    ft_printf("The car you have choosen is %s.\n", map->car.name);
    ft_printf("The car you have choosen is %s.\n", map->car.name);
    map->flag = 0;
    map->car_amount = 0;
    map->ways_amount = 0;
    map->km = 0;
    map->mileage = 0;
    map->start_station_id = -1;
    map->end_station_id = -1;
    map->init = (t_list_stations*)malloc(sizeof(t_list_stations));
    map->init->next = NULL;
    map->init->prev = NULL;
    map->dop = map->init;
}


int		work(t_map *map)
{
	t_car *cars;

	if (map->flag == 1 && is_valid_map(*map) && is_answer(*map))
	{
		ft_printf("\n");
		map->ways = (t_list_stations**)malloc(sizeof(t_list_stations*) *
				map->station[map->end_station_id].links_amount);
		find_ways(map, 0);
		print_ways(*map);
		move_cars(*map);
		return (1);
	}
	return (write_error("ERROR"));
}

int		not_comment_not_links(t_map *map, char **line, int *i)
{
	if (!ft_isalnum((*line)[0]))
		return (0);
	if (!ft_strchr(*line, '#') && !ft_strchr(*line, '-'))
	{
		if (map->flag == 1)
		{
			map->flag = 2;
			return (0);
		}
		if (*i > 0 && !ft_strchr(*line, ' '))
			return (write_error("INCORRECT INPUT"));
		if (!get_info(map, *line, i))
		{
			ft_strdel(line);
			return (0);
		}
		return (1);
	}
	return (1);
}

int		not_comment_but_links(t_map *map, char **line)
{
	if (!ft_isalnum((*line)[0]) || map->flag == 2)
		return (0);
	if (!ft_strchr(*line, '#') && ft_strchr(*line, '-'))
	{
		if (map->flag == 0)
		{
			if (map->start_station_id == -1 || map->end_station_id == -1)
				return (write_error("THERE IS NO START OR END ROOM. ERROR"));
			make_stations(map);
			map->flag = 1;
		}
		if (!find_link(map, line, 0))
		{
			ft_strdel(line);
			return (write_error("INVALID ROOM OR LINK. ERROR"));
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;
	t_map	map;

	i = 0;
	fd = open("/home/echufy/diplom/map.txt", O_RDONLY);
	init(&map, av);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			if (ft_strchr(line, '#') && get_start_end(&map, &line))
				continue;
			else if (!not_comment_not_links(&map, &line, &i))
				break ;
			else if (!not_comment_but_links(&map, &line))
				break ;
			ft_strdel(&line);
		}
		else
			return (write_error("ERROR"));
	}
	return (work(&map) * ac);
}
