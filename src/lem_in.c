/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/26 13:40:00 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(int argc, const char **argv)
{
	t_control	control;
	t_room		*rooms;
	t_ant		*ants;

	rooms = NULL;
	ants = NULL;
	ft_bzero(&control, sizeof(t_control));
	if (read_map(&rooms, &ants, &control) && !control.map_has_anomaly)
	{
		process_commands(rooms, control);
		if (control.ant_count > 0 && control.start && control.end)
		{
			mark_shortest_path(rooms);
			herd_ants();
			smash_ant_farm();
		}
	}
	else
		ft_putstr("Map error!\n");
	return (0);
}
