/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:33:27 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/05 19:27:58 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct			    s_point
{
	int x;
	int y;
}						    t_point;

typedef struct			    s_charge_speed
{
    int midd_charge;
    int fast_charge;
}						    t_charge_speed;

typedef struct			    s_charge_st
{
	int				    	id;
	char			    	*name;
	t_charge_speed		    charges;
    float                  distance_to_next_station;
	int				    	*links;
	int				    	links_amount;
	int					    flag;
}						    t_charge_st;

typedef struct			    s_list_charges
{
	int					    id;
	char				    *name;
    t_charge_speed		    charges;
    float                  distance_to_next_station;
	int					    *links;
	int					    links_amount;
	int					    size;
	char				    *color;
	struct s_list_charges	*prev;
	struct s_list_charges	*next;
}						    t_list_charges;

typedef struct		    	s_farm
{
	int					    ants_amount;
	int					    room_amount;
	int					    ways_amount;
	int				    	flag;
	int					    col;
	int				    	lines;
	int				    	start_room_id;
	int				    	end_room_id;
	char			    	**colors;
	t_list_charges	    	*init;
	t_list_charges	    	*dop;
	t_charge_st		    	*rooms;
	t_list_charges	    	**ways;
}					    	t_farm;

typedef struct		    	s_ant
{
	int				    	number;
	t_list_charges	    	*way;
	int				    	way_size;
	int				    	currnet_index;
}					       	t_ant;

void				       	init2(t_farm *farm);
int					    	is_room(t_farm farm, char *name);
int					    	is_answer(t_farm farm);
int				    		is_valid_name(t_farm farm, const char *name);
int				    		is_valid_map(t_farm farm);
int				    		is_coord(t_farm farm, t_list_charges *room);
int				    		find_link(t_farm *farm, char **line, int k);
void			    		add_link(t_farm *farm, char *line, int i);
int				    		ft_list_room_find(t_list_charges *room_list, int id);
int				    		ft_list_size(t_list_charges *room_list);
int				    		get_start_end(t_farm *farm, char **line);
int					    	get_info(t_farm *farm, char *line, int *i);
void				    	get_way(t_farm *farm, t_list_charges *way, int flag);
void			    		find_ways(t_farm *farm, int flag);
void			    		print_ways(t_farm farm);
void				    	bzero_ways(t_farm *farm);
void			    		print_ants_movings(t_ant *ants, int ants_amount);
int				    		bonus_ways(t_farm farm, char **av);
int				    		bonus_lines(t_farm farm, char **av);
void				    	room_init(t_farm *farm);
void			    		make_room(t_farm *farm);
void			    		free_list(t_list_charges **dop);
int				    		move_ants(t_farm farm, t_ant *ants);
int				    		write_error(char *s);
void			       		write_line(char *line);
void			    		the_end(void);
t_ant			    		*create_ants(int ants_amount);
t_list_charges	    			*ft_list_room_new(t_charge_st room);

#endif
