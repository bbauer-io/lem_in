/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 18:35:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		init_to_null(t_room ***rooms, t_ant ***ants, char ***map,
															t_control *control)
{
	*map = NULL;
	*rooms = NULL;
	*ants = NULL;
	ft_bzero(control, sizeof(t_control));
}

int				main(int argc, char **argv)
{
	t_control	control;
	t_room		**rooms;
	t_ant		**ants;
	char		**map;

	init_to_null(&rooms, &ants, &map, &control);
	if (argc == 2 && **(++argv) == '-' && (*argv)[1] == 'v')
		control.debug = 1;
	if ((map = read_map(&rooms, &control, map)) && !control.map_has_anomaly
			&& control.ant_count > 0 && control.start && control.end)
	{
		ft_print_tab(map);
		ft_tab_del(&map);
		ants = summon_ants(&control);
		mark_shortest_path(control.end, &control);
		if (control.debug)
			print_map_debug(rooms);
		ants_go_marching(rooms, ants, &control);
		vanish_ant_farm(&rooms, &ants, &map);
	}
	else
		ft_putstr("Map error!\n");
	return (0);
}
