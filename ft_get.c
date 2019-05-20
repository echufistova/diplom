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

int		get_cood(t_farm *farm, char **line, int n)
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
		farm->init->charges.midd_charge = ft_atoi(dopline);
        ft_printf("midd_charge: %d\n", farm->init->charges.midd_charge);
		if (!get_cood(farm, line, 1))
			return (0);
	}
	else if (n == 1)
	{
		farm->init->charges.fast_charge = ft_atoi(dopline);
		ft_printf("fast_charge: %d\n", farm->init->charges.fast_charge);
		if (!get_cood(farm, line, 2))
			return (0);
	}
	else if (n == 2)
	{
		farm->init->distance_to_next_station = strtod(dopline, NULL);
		printf("distance: %f\n", farm->init->distance_to_next_station);
	}
	return (1);
}

int		get_info(t_farm *farm, char *line, int *i)
{
	char *dop;
	char *dop2;

	if ((*i) == 0)
	{
		farm->ants_amount = ft_atoi(line);
		(*i)++;
	}
	else if (ft_strchr(line, '-') == NULL)
	{
		dop = ft_strchr(line, ' ');
		dop2 = ft_strsub(line, 0, dop - line);
		if (!is_valid_name(*farm, dop2))
		{
			ft_strdel(&dop2);
			return (0);
		}
		farm->init->id = farm->room_amount;
		farm->init->name = ft_strdup(dop2);
		ft_strdel(&dop2);
        if (!get_cood(farm, &dop, 0))
            return (0);
		room_init(farm);
	}
	return (1);
}

int		get_start_end(t_farm *farm, char **line)
{
	if (ft_strcmp(*line, "##start") == 0 && farm->start_room_id == -1)
	{
		farm->start_room_id = farm->room_amount;
		ft_strdel(line);
		return (1);
	}
	else if (ft_strcmp(*line, "##end") == 0 && farm->end_room_id == -1)
	{
		farm->end_room_id = farm->room_amount;
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

void	room_init(t_farm *farm)
{
	farm->init->links_amount = 0;
	farm->init->next = (t_list_charges*)malloc(sizeof(t_list_charges));
	farm->init = farm->init->next;
	farm->init->color = NULL;
	farm->init->next = NULL;
	farm->init->prev = NULL;
	farm->room_amount++;
}

void	init2(t_farm *farm)
{
	farm->flag = 0;
	farm->room_amount = 0;
	farm->ways_amount = 0;
	farm->start_room_id = -1;
	farm->end_room_id = -1;
	farm->init = (t_list_charges*)malloc(sizeof(t_list_charges));
	farm->init->next = NULL;
	farm->init->prev = NULL;
	farm->dop = farm->init;
}
