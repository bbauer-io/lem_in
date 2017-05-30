/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:22:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 06:29:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Checks that a string contains only digits up to the null terminator. Returns
** 0 if it finds any other characters. checks n characters of the string unless
** n is < 1 in which case it checks the entire string.
*/

int				line_is_numeric(char *line)
{
	while (line && *line)
		if (!ft_isdigit(*(line++)))
			return (0);
	return (1);
}

/*
** add_room copies src_tab to a new table with space for one more entry,
** then copies that entry and adds a pointer to it in the new table.
** Returns the new (char **) table.
*/

t_room			**add_room(t_room **src_tab, t_room *new_item)
{
	int		tab_len;
	t_room	**new_tab;

	tab_len = 0;
	while (src_tab && src_tab[tab_len])
		tab_len++;
	new_tab = (t_room **)malloc(sizeof(t_room *) * (tab_len + 2));
	ft_bzero(new_tab, sizeof(t_room *) * (tab_len + 2));
	ft_memcpy(new_tab, src_tab, sizeof(t_room *) * tab_len);
	new_tab[tab_len] = new_item;
	new_tab[++tab_len] = NULL;
	free(src_tab);
	return (new_tab);
}

void			read_room(t_room ***rooms, char *line, char ***commands,
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

void			read_tunnel(t_room **rooms, char *line, t_control *control)
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

int				read_ant_count(char *line, t_control *control)
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
