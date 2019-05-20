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

typedef struct			    s_station
{
	int				    	id;
	char			    	*name;
	t_charge_speed		    charges;
    float                   distance_to_next_station;
	int				    	*links;
	int				    	links_amount;
	int					    flag;
}						    t_station;

typedef struct			    s_list_stations
{
	int					    id;
	char				    *name;
    t_charge_speed		    charges;
    float                  distance_to_next_station;
	int					    *links;
	int					    links_amount;
	int					    size;
	char				    *color;
	struct s_list_stations	*prev;
	struct s_list_stations	*next;
}						    t_list_stations;

typedef struct		    	s_car
{
    char *name;
	int				    	number;
	int                     max_speed;
	int                     mileage;
	float                   time_midd_charge;
    float                   time_fast_charge;
	t_list_stations	    	*way;
	int				    	way_size;
	int				    	currnet_index;
}					       	t_car;

typedef struct		    	s_farm
{
    int					    ants_amount;
    int					    room_amount;
    int					    ways_amount;
    int				    	flag;
    int				    	lines;
    int				    	start_room_id;
    int				    	end_room_id;
    t_list_stations	    	*init;
    t_list_stations	    	*dop;
    t_list_stations	    	**ways;
    t_station		    	*rooms;
    t_car                   car;
}					    	t_farm;

int					    	is_room(t_farm farm, char *name);
int					    	is_answer(t_farm farm);
int				    		is_valid_name(t_farm farm, const char *name);
int				    		is_valid_map(t_farm farm);
int				    		find_link(t_farm *farm, char **line, int k);
void			    		add_link(t_farm *farm, char *line, int i);
int				    		ft_list_room_find(t_list_stations *room_list, int id);
int				    		ft_list_size(t_list_stations *room_list);
int				    		get_start_end(t_farm *farm, char **line);
int					    	get_info(t_farm *farm, char *line, int *i);
void				    	get_way(t_farm *farm, t_list_stations *way, int flag);
void			    		find_ways(t_farm *farm, int flag);
void			    		print_ways(t_farm farm);
void				    	bzero_ways(t_farm *farm);
void			    		print_ants_movings(t_car *ants, int ants_amount);
int				    		bonus_ways(t_farm farm, char **av);
int				    		bonus_lines(t_farm farm, char **av);
void				    	room_init(t_farm *farm);
void			    		make_room(t_farm *farm);
void			    		free_list(t_list_stations **dop);
int				    		move_ants(t_farm farm, t_car *ants);
int				    		write_error(char *s);
void			    		the_end(void);
t_car			    		*create_ants(int ants_amount);
t_list_stations	    		*ft_list_room_new(t_station room);

static const t_car nissan_leaf =
        {
                "Nissan Leaf", 1, 144, 250, 3, 0.5, NULL, 0
        };

static const t_car bmw_i3 =
        {
                "BMW i3", 2, 150, 300, 3.25, 0.6667, NULL, 0
        };

static const t_car tesla_model_s =
        {
                "Tesla Model S", 3, 225, 480, 6, 1, NULL, 0
        };

#endif
