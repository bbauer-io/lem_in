/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 10:22:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	t_control	control;
	t_room		**rooms;
	t_ant		**ants;

	rooms = NULL;
	ants = NULL;
	ft_bzero(&control, sizeof(t_control));
	if (read_map(&rooms, &control) && !control.map_has_anomaly)
	{
		print_map_debug(rooms, &control);
		if (control.ant_count > 0 && control.start && control.end)
		{
//			generate_ants(&ants);
//			invoke_shortest_path(rooms);
//			herd_ants();
//			smash_ant_farm();
		}
	}
	else
		ft_putstr("Map error!\n");
	return (0);
}
