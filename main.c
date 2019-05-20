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

void	init(t_farm *farm, char **av)
{

    if (ft_atoi(av[1]) == 1)
        farm->car = nissan_leaf;
    else if (ft_atoi(av[1]) == 1)
        farm->car = bmw_i3;
    else if (ft_atoi(av[1]) == 1)
        farm->car = tesla_model_s;
    ft_printf("The car you have choosen is %s.\n", farm->car.name);
    farm->flag = 0;
    farm->room_amount = 0;
    farm->ways_amount = 0;
    farm->start_room_id = -1;
    farm->end_room_id = -1;
    farm->init = (t_list_stations*)malloc(sizeof(t_list_stations));
    farm->init->next = NULL;
    farm->init->prev = NULL;
    farm->dop = farm->init;
}


int		work(t_farm *farm, char **av)
{
	t_car *ants;

	if (farm->flag == 1 && is_valid_map(*farm) && is_answer(*farm))
	{
		ft_printf("\n");
		farm->ways = (t_list_stations**)malloc(sizeof(t_list_stations*) *
				farm->rooms[farm->end_room_id].links_amount);
		find_ways(farm, 0);
		bonus_ways(*farm, av);
		ants = create_ants(farm->ants_amount);
		farm->lines = move_ants(*farm, ants);
		free(ants);
		if (!bonus_lines(*farm, av))
			return (0);
		the_end();
		return (1);
	}
	return (write_error("ERROR"));
}

int		not_comment_not_links(t_farm *farm, char **line, int *i)
{
	if (!ft_isalnum((*line)[0]))
		return (0);
	if (!ft_strchr(*line, '#') && !ft_strchr(*line, '-'))
	{
		if (farm->flag == 1)
		{
			farm->flag = 2;
			return (0);
		}
		if (*i > 0 && !ft_strchr(*line, ' '))
			return (write_error("INCORRECT INPUT"));
		if (!get_info(farm, *line, i))
		{
			ft_strdel(line);
			return (0);
		}
		return (1);
	}
	return (1);
}

int		not_comment_but_links(t_farm *farm, char **line)
{
	if (!ft_isalnum((*line)[0]) || farm->flag == 2)
		return (0);
	if (!ft_strchr(*line, '#') && ft_strchr(*line, '-'))
	{
		if (farm->flag == 0)
		{
			if (farm->start_room_id == -1 || farm->end_room_id == -1)
				return (write_error("THERE IS NO START OR END ROOM. ERROR"));
			make_room(farm);
			farm->flag = 1;
		}
		if (!find_link(farm, line, 0))
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
	t_farm	farm;

	i = 0;
	fd = open("/home/echufy/diplom/map.txt", O_RDONLY);
	init(&farm, av);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			if (ft_strchr(line, '#') && get_start_end(&farm, &line))
				continue;
			else if (!not_comment_not_links(&farm, &line, &i))
				break ;
			else if (!not_comment_but_links(&farm, &line))
				break ;
			ft_strdel(&line);
		}
		else
			return (write_error("ERROR"));
	}
	return (work(&farm, av) * ac);
}
