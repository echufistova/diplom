/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:55:03 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 19:27:03 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_cood(t_map *map, char **line, int n)
{
	char *dopline;

	if (!ft_isdigit((++(*line))[0]))
		return (write_error("INCORRECT INPUT. ERROR"));
	dopline = *line;
	while (**line != ' ' && **line != '\0')
	{
		if (!ft_isdigit(**line) && **line != '.')
			return (write_error("INCORRECT INPUT. ERROR"));
		++(*line);
	}
	if (n == 0)
	{
		ft_printf("HELLO\n");
		map->init->charges.midd_charge = ft_atoi(dopline);
        ft_printf("midd_charge: %d\n", map->init->charges.midd_charge);
		if (!get_cood(map, line, 1))
			return (0);
	}
	else if (n == 1)
	{
		map->init->charges.fast_charge = ft_atoi(dopline);
		ft_printf("fast_charge: %d\n", map->init->charges.fast_charge);
		if (!get_cood(map, line, 2))
			return (0);
	}
	else if (n == 2)
	{
		map->init->distance_to_next_station = strtod(dopline, NULL);
		printf("distance: %f\n", map->init->distance_to_next_station);
	}
	return (1);
}

int		get_info(t_map *map, char *line, int *i)
{
	char *dop;
	char *dop2;

	if ((*i) == 0)
	{
		map->cars_amount = ft_atoi(line);
		(*i)++;
	}
	else if (ft_strchr(line, '-') == NULL)
	{
		dop = ft_strchr(line, ' ');
		dop2 = ft_strsub(line, 0, dop - line);
		if (!is_valid_name(*map, dop2))
		{
			ft_strdel(&dop2);
			return (0);
		}
		map->init->id = map->car_amount;
		map->init->name = ft_strdup(dop2);
		ft_strdel(&dop2);
        if (!get_cood(map, &dop, 0))
            return (0);
		station_init(map);
	}
	return (1);
}

int		get_start_end(t_map *map, char **line)
{
	if (ft_strcmp(*line, "##start") == 0 && map->start_station_id == -1)
	{
		map->start_station_id = map->car_amount;
		ft_strdel(line);
		return (1);
	}
	else if (ft_strcmp(*line, "##end") == 0 && map->end_station_id == -1)
	{
		map->end_station_id = map->car_amount;
		ft_strdel(line);
		return (1);
	}
	else if (ft_strcmp(*line, "##end") == 0 || !ft_strcmp(*line, "##start"))
		return (write_error("INCORRECT INPUT. ERROR"));
	else if ((*line)[0] == '#')
	{
		ft_strdel(line);
		return (1);
	}
	else
		return (0);
}

void	station_init(t_map *map)
{
	map->init->links_amount = 0;
	map->init->next = (t_list_stations*)malloc(sizeof(t_list_stations));
	map->init = map->init->next;
	map->init->next = NULL;
	map->init->prev = NULL;
	map->car_amount++;
}