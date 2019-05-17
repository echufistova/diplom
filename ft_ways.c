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

void	get_way_dop(t_farm *farm, t_list_charges **new)
{
	if (farm->col != -1)
		farm->ways[farm->ways_amount]->color = farm->colors[farm->col++];
	if (farm->col == 5)
		farm->col = 0;
	farm->ways_amount++;
	free_list(new);
}

void	get_way(t_farm *farm, t_list_charges *way, int flag)
{
	t_list_charges *rm;
	t_list_charges *dop;
	t_list_charges *new;

	bzero_ways(farm);
	farm->ways[farm->ways_amount] = ft_list_room_new(farm->rooms[
			farm->start_room_id]);
	dop = farm->ways[farm->ways_amount];
	rm = way->prev;
	while (rm->id != farm->end_room_id)
	{
		farm->ways[farm->ways_amount]->next = ft_list_room_new(farm->rooms
				[rm->id]);
		farm->ways[farm->ways_amount] = farm->ways[farm->ways_amount]->next;
		farm->rooms[rm->id].flag = 2;
		rm = rm->prev;
	}
	new = rm;
	farm->ways[farm->ways_amount]->next = ft_list_room_new(farm->rooms[
			rm->id]);
	farm->ways[farm->ways_amount] = dop;
	farm->ways[farm->ways_amount]->size = ft_list_size(farm->ways[
			farm->ways_amount]) - 1;
	get_way_dop(farm, &new);
	find_ways(farm, flag);
}

int		find_ways_dop(t_farm *farm, t_list_charges **way,
						 t_list_charges *dop2, t_point i)
{
	if ((*way)->id != farm->end_room_id && (*way)->id != -1)
		farm->rooms[(*way)->id].flag = 1;
	if ((*way)->links_amount == 1 && (*way)->links[0] ==
						farm->start_room_id)
	{
		(*way)->next = ft_list_room_new(farm->rooms[dop2->links[i.x]]);
		(*way) = (*way)->next;
		(*way)->prev = dop2;
		get_way(farm, (*way), 1);
		return (0);
	}
	if (dop2->links[i.x] != farm->end_room_id)
	{
		(*way)->next = ft_list_room_new(farm->rooms[dop2->links[i.x]]);
		(*way) = (*way)->next;
		(*way)->prev = dop2;
		if ((*way)->id == farm->start_room_id)
		{
			get_way(farm, (*way), i.y);
			return (0);
		}
	}
	return (1);
}

void	find_ways(t_farm *farm, int flag)
{
	t_point			i;
	t_list_charges	*way;
	t_list_charges	*dop2;
	t_list_charges	*dop;

	way = ft_list_room_new(farm->rooms[farm->end_room_id]);
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
			if (farm->rooms[dop2->links[i.x]].flag != 1 && farm->rooms[
		dop2->links[i.x]].flag != 2 && !find_ways_dop(farm, &way, dop2, i))
				return ;
		}
		dop2 = dop2->next;
	}
	free_list(&dop);
	bzero_ways(farm);
}

void	print_ways(t_farm farm)
{
	int			i;
	t_list_charges	*ways;

	i = 0;
	ft_printf("Amount of ways: %d\n", farm.ways_amount);
	while (i < farm.ways_amount)
	{
		ways = farm.ways[i];
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
