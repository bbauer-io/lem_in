/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:44:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 06:47:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Marks where the ants should be placed at the beginning of the program.
*/

static void		is_start(t_room *room, t_control *control)
{
	if (!control->start && !room->is_start)
	{
		room->is_start = 1;
		control->start = room;
	}
	else
		control->map_has_anomaly = 1;
}

/*
** Marks where the ants should go at the end of the program.
*/

static void		is_end(t_room *room, t_control *control)
{
	if (!control->end && !room->is_end)
	{
		room->is_end = 1;
		control->end = room;
	}
	else
		control->map_has_anomaly = 1;
}

/*
** Matches a text command to an available function (or ignores it if no match).
** The functions will mark the relevant field in the room struct.
*/

void			process_commands(t_room *room, t_control *control)
{
	int		i;

	i = 0;
	while (room->commands[i])
	{
		if (ft_strequ(room->commands[i], "start"))
			is_start(room, control);
		else if (ft_strequ(room->commands[i], "end"))
			is_end(room, control);
		i++;
	}
}
