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
	{
		print_map_debug(*rooms);
		print_control_debug(control);
	}
	return (map);
}
