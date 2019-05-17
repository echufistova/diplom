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

void	add_link(t_farm *farm, char *line, int i)
{
	int		j;
	t_charge_st	dop_rm;

	j = 0;
	if (farm->rooms[i].links_amount > 0)
	{
		dop_rm.name = NULL;
		dop_rm.flag = 0;
		dop_rm.links_amount = farm->rooms[i].links_amount;
		dop_rm.links = (int*)malloc(sizeof(int) * farm->rooms[i].links_amount);
		j = -1;
		while (++j < farm->rooms[i].links_amount)
			dop_rm.links[j] = farm->rooms[i].links[j];
		free(farm->rooms[i].links);
		farm->rooms[i].links = (int*)malloc(sizeof(int) *
				(farm->rooms[i].links_amount + 1));
		j = -1;
		while (++j < farm->rooms[i].links_amount)
			farm->rooms[i].links[j] = dop_rm.links[j];
		free(dop_rm.links);
	}
	else
		farm->rooms[i].links = (int*)malloc(sizeof(int));
	farm->rooms[i].links[j] = is_room(*farm, line);
	farm->rooms[i].links_amount++;
}

int		find_link_dop(t_farm farm, char *dop, char **name, t_point ij)
{
	while (++ij.y < farm.rooms[ij.x].links_amount)
		if (farm.rooms[ij.x].links[ij.y] == is_room(farm, dop))
		{
			ft_strdel(name);
			return (0);
		}
	return (1);
}

int		find_link(t_farm *farm, char **line, int k)
{
	t_point	ij;
	char	*dop;
	char	*name;

	ij.y = -1;
	dop = ft_strchr(*line, '-');
	name = ft_strsub(*line, 0, dop - *line);
	ij.x = is_room(*farm, name);
	if (ij.x > -1 && is_room(*farm, ++dop) > -1 && ij.x != is_room(*farm, dop))
	{
		if (!find_link_dop(*farm, dop, &name, ij))
			return (0);
		add_link(farm, dop, ij.x);
		if (++k < 2)
		{
			dop = ft_strcat(ft_strcat(dop, "-"), name);
			find_link(farm, &dop, k);
		}
		ft_strdel(&name);
		return (1);
	}
	ft_strdel(&name);
	ft_strdel(line);
	return (0);
}

int		is_room(t_farm farm, char *name)
{
	int i;

	i = 0;
	if (name)
	{
		while (i < farm.room_amount)
		{
			if (ft_strcmp(farm.rooms[i].name, name) == 0)
				return (i);
			i++;
		}
	}
	return (-1);
}

void	make_room(t_farm *farm)
{
	int			    i;
	t_list_charges	*dop2;

	i = 0;
	farm->rooms = (t_charge_st*)malloc(sizeof(t_charge_st) * farm->room_amount);
	dop2 = farm->dop;
	farm->dop->size = ft_list_size(farm->dop);
	while (dop2->next)
	{
		farm->rooms[i].id = dop2->id;
		farm->rooms[i].name = ft_strdup(dop2->name);
		farm->rooms[i].coord.x = dop2->coord.x;
		farm->rooms[i].coord.y = dop2->coord.y;
		farm->rooms[i].links_amount = 0;
		farm->rooms[i].links = NULL;
		dop2 = dop2->next;
		i++;
	}
}
