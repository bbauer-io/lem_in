/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 08:44:31 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/31 18:18:59 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		print_debug_info(t_room **rooms, t_control *control)
{
	print_map_debug(rooms);
	print_control_debug(control);
}

/*
** Called when a line on the std input should contain a description of a room.
** After determining that the line contains a valid room name and coordiates, it
** saves the room name and coordinates in a new_room struct, and attaches any
** commands that thave been listed before.
*/

static void		read_room(t_room ***rooms, char *line, char ***commands,
														t_control *control)
{
	char	**arr;
	t_room	*new_room;

	arr = ft_strtok(line, " ");
	if (!arr || !line_is_numeric(arr[1]) || !line_is_numeric(arr[2])
		|| ft_char_count(line, ' ') != 2 || *(ft_strchr(line, ' ') + 1) == ' '
		|| *line == 'L' || control->has_tunnels || ft_strchr(arr[0], '-')
		|| room_search(*rooms, arr[0]))
	{
		control->map_has_anomaly = 1;
		return ;
	}
	new_room = (t_room *)malloc(sizeof(t_room));
	ft_bzero(new_room, sizeof(t_room));
	new_room->name = ft_strdup(arr[0]);
	new_room->x_coord = ft_atoi(arr[1]);
	new_room->y_coord = ft_atoi(arr[2]);
	ft_tab_del(&arr);
	if (commands && *commands && **commands)
		attach_commands_to_room(new_room, commands, control);
	*rooms = add_room(*rooms, new_room);
	control->has_rooms = 1;
}

/*
** Called whena line on the std input describes a connection between two rooms.
** the connection is noted on the structs of the rooms on each end.
*/

static void		read_tunnel(t_room **rooms, char *line, t_control *control)
{
	char	**arr;
	t_room	*left_room;
	t_room	*right_room;

	if (ft_char_count(line, '-') > 1)
	{
		control->map_has_anomaly = 1;
		return ;
	}
	arr = ft_strsplit(line, '-');
	left_room = NULL;
	right_room = NULL;
	left_room = room_search(rooms, arr[0]);
	right_room = room_search(rooms, arr[1]);
	if (!left_room || !right_room)
	{
		control->map_has_anomaly = 1;
		return ;
	}
	left_room->connections = add_room(left_room->connections, right_room);
	right_room->connections = add_room(right_room->connections, left_room);
	control->has_tunnels = 1;
	ft_tab_del(&arr);
}

/*
** This is where each line of the map is evaluated to determine what information
** is contained. Lines starting with "##" are commands, "#" are comments,
** "name 1 1" are rooms with coordinates, "name-name" pairs are connections
** between the rooms, anything else is an anomaly and will result in an error
** message, then end the program.
*/

static char		**evaluate_line(t_room ***rooms, t_control *control, char *line,
														char **commands)
{
	char	**tmp;

	if (*line == '#' && line[1] != '#' && !commands)
		;
	else if (*line == '#' && line[1] == '#' && !commands)
	{
		tmp = commands;
		commands = ft_tab_add_one(commands, &line[2]);
		if (tmp)
			free(tmp);
	}
	else if (control->ant_count < 1 && !control->has_rooms
				&& !control->has_tunnels && !commands)
		read_ant_count(line, control);
	else if (ft_strchr(line, ' '))
		read_room(rooms, line, &commands, control);
	else if (commands)
		control->map_has_anomaly = 1;
	else if (ft_strchr(line, '-'))
		read_tunnel(*rooms, line, control);
	else
		control->map_has_anomaly = 1;
	ft_strdel(&line);
	return (commands);
}

/*
** This will read input from the map from a map file which should be placed on
** std in (./lem_in < map). It reads one line at a time and saves the entire
** file for printing if the entire map is determined to be valid.
*/

char			**read_map(t_room ***rooms, t_control *control, char **map)
{
	char	*line;
	char	**commands;
	char	**tmp;

	line = NULL;
	commands = NULL;
	while (get_next_line(0, &line))
	{
		tmp = map;
		map = ft_tab_add_one(map, line);
		if (tmp)
			free(tmp);
		commands = evaluate_line(rooms, control, line, commands);
		if (control->map_has_anomaly)
		{
			ft_tab_del(&map);
			return (NULL);
		}
	}
	free(line);
	if (commands)
		ft_tab_del(&commands);
	if (control->debug)
		print_debug_info(*rooms, control);
	return (map);
}
