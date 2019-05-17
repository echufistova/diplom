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
	int i;

	i = 0;
	if ((av[1] && av[1][0] == '-' && av[1][1] == 'c' && ft_strlen(av[1]) == 2)
	|| (av[2] && av[2][0] == '-' && av[2][1] == 'c' && ft_strlen(av[2]) == 2)
	|| (av[3] && av[3][0] == '-' && av[3][1] == 'c' && ft_strlen(av[3]) == 2))
	{
		farm->colors = (char**)malloc(sizeof(char*) * 5);
		while (i < 5)
			farm->colors[i++] = (char*)malloc(sizeof(char) * 8);
		farm->colors[0] = ft_strcpy(farm->colors[0], "\e[91m");
		farm->colors[1] = ft_strcpy(farm->colors[1], "\e[92m");
		farm->colors[2] = ft_strcpy(farm->colors[2], "\e[93m");
		farm->colors[3] = ft_strcpy(farm->colors[3], "\e[94m");
		farm->colors[4] = ft_strcpy(farm->colors[4], "\e[95m");
		farm->col = 0;
	}
	else
	{
		farm->col = -1;
		farm->colors = NULL;
	}
	init2(farm);
}

int		work(t_farm *farm, char **av)
{
	t_ant *ants;

	if (farm->flag == 1 && is_valid_map(*farm) && is_answer(*farm))
	{
		ft_printf("\n");
		farm->ways = (t_list_charges**)malloc(sizeof(t_list_charges*) *
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
