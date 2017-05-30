/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:22:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 07:48:42 by bbauer           ###   ########.fr       */
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
	if (line && *line == '-')
		line++;
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

void			attach_commands_to_room(t_room *new_room, char ***commands,
															t_control *control)
{
	new_room->commands = *commands;
	process_commands(new_room, control);
	*commands = NULL;
}

/*
** The first line of the struct should contain a number describing the number of
** ants that are to be used. This function reads and validates that line.
*/

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
