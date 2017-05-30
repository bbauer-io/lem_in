/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 08:44:31 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 17:36:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		read_room(t_room ***rooms, char *line, char ***commands,
														t_control *control)
{
	char	**arr;
	t_room	*new_room;

	arr = ft_strtok(line, " ");
	if (!arr || !line_is_numeric(arr[1]) || !line_is_numeric(arr[2])
		|| ft_char_count(line, ' ') != 2 || *(ft_strchr(line, ' ') + 1) == ' '
		|| *line == 'L' || control->has_tunnels || room_search(*rooms, arr[0]))
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
	{
		new_room->commands = *commands;
		process_commands(new_room, control);
		*commands = NULL;
	}
	*rooms = add_room(*rooms, new_room);
	control->has_rooms = 1;
}

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

static int		read_ant_count(char *line, t_control *control)
{
	if (line_is_numeric(line) && ft_atoi(line) > 0)
	{
		control->ant_count = ft_atoi(line);
		return (1);
	}
	else
	{
		control->map_has_anomaly = 1;
		return (0);
	}
}

static char		**evaluate_line(t_room ***rooms, t_control *control, char *line,
														char **commands)
{
	char	**tmp;

	if (*line == '#' && line[1] != '#')
		;
	else if (*line == '#' && line[1] == '#')
	{
		tmp = commands;
		commands = ft_tab_add_one(commands, &line[2]);
		free(tmp);
	}
	else if (control->ant_count < 1 && !control->has_rooms
				&& !control->has_tunnels)
		read_ant_count(line, control);
	else if (ft_strchr(line, ' '))
		read_room(rooms, line, &commands, control);
	else if (ft_strchr(line, '-'))
		read_tunnel(*rooms, line, control);
	else
		control->map_has_anomaly = 1;
	ft_strdel(&line);
	return (commands);
}

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
		ft_tab_del(&tmp);
		commands = evaluate_line(rooms, control, line, commands);
		if (control->map_has_anomaly)
		{
			ft_tab_del(&map);
			return (NULL);
		}
	}
	if (commands)
		ft_tab_del(&commands);
	if (control->debug)
	{
		print_map_debug(*rooms);
		print_control_debug(control);
	}
	return (map);
}
