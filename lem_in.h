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
    float                   distance_to_next_station;
	int					    *links;
	int					    links_amount;
	int					    size;
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

typedef struct		    	s_map
{
    int					    cars_amount;
    int					    room_amount;
    int					    ways_amount;
    int                     km;
    int                     mileage;
    int				    	flag;
    int				    	lines;
    int				    	start_room_id;
    int				    	end_room_id;
    t_list_stations	    	*init;
    t_list_stations	    	*dop;
    t_list_stations	    	**ways;
    t_station		    	*rooms;
    t_car                   car;
}					    	t_map;

int					    	is_room(t_map map, char *name);
int					    	is_answer(t_map map);
int				    		is_valid_name(t_map map, const char *name);
int				    		is_valid_map(t_map map);
int				    		find_link(t_map *map, char **line, int k);
void			    		add_link(t_map *map, char *line, int i);
int				    		ft_list_room_find(t_list_stations *room_list, int id);
int				    		ft_list_size(t_list_stations *room_list);
int				    		get_start_end(t_map *map, char **line);
int					    	get_info(t_map *map, char *line, int *i);
void				    	get_way(t_map *map, t_list_stations *way, int flag);
void			    		find_ways(t_map *map, int flag);
void				    	bzero_ways(t_map *farm);
void			    		print_cars_movings(t_car *cars, int cars_amount);
void				    	room_init(t_map *map);
void			    		make_room(t_map *map);
void			    		free_list(t_list_stations **dop);
int				    		move_cars(t_map map, t_car *cars);
int				    		write_error(char *s);
t_car			    		*create_cars(int cars_amount);
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
