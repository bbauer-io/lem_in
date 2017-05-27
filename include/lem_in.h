/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 10:24:21 by bbauer           ###   ########.fr       */
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
	char			*occupant;
	char			**commands;
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
}					t_control;

typedef struct		s_ant
{
	char			*name;
	int				ant_num;
}					t_ant;

typedef struct		s_com
{
	char			*com;
	char			*next;
}					t_com;

int					read_map(t_room ***rooms, t_control *control);
t_room				**add_room(t_room **src_tab, t_room *new_item);
int					line_is_numeric(char *line);
t_room				*room_search(t_room **rooms, char *search);
void				process_commands(t_room *room, t_control *control);

/*
** For testing only.
*/

void				print_map_debug(t_room **rooms, t_control *control);

#endif
