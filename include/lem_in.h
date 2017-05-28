/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 22:29:13 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_room
{
	t_bool			is_end;
	t_bool			is_start;
	t_bool			is_occupied;
	char			*name;
	char			**commands;
	int				occupant_count;
	int				steps_to_exit;
	size_t			x_coord;
	size_t			y_coord;
	struct s_room	**connections;
}					t_room;

typedef struct		s_control
{
	int				ant_count;
	t_room			*start;
	t_room			*end;
	t_bool			has_rooms;
	t_bool			has_tunnels;
	t_bool			found_path;
	t_bool			map_has_anomaly;
	t_bool			debug;
}					t_control;

typedef struct		s_ant
{
	char			*name;
	t_room			*location;
	int				serial;
	t_bool			moving;
}					t_ant;

typedef struct		s_com
{
	char			*com;
	s_com			*next;
}					t_com;

/*
** Lem-in functions
*/

char				**read_map(t_room ***rooms, t_control *control, char **map);
t_room				**add_room(t_room **src_tab, t_room *new_item);
int					line_is_numeric(char *line);
t_room				*room_search(t_room **rooms, char *search);
void				process_commands(t_room *room, t_control *control);
t_ant				**summon_ants(t_control *control);
void				mark_shortest_path(t_room *room, t_control *control);
t_room				**queue_rem_one(t_room **src, size_t rem);
void				ants_go_marching(t_ant **ants, t_control *control);
void				vanish_ant_farm(t_room ***rooms, t_ant ***ants,
														char ***map);

/*
** Lem-in debugging functions
*/

void				print_map_debug(t_room **rooms);
void				print_ants_debug(t_ant **ants);
void				print_control_debug(t_control *control);

#endif
