/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 22:29:43 by bbauer           ###   ########.fr       */
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

static void		no_path_error(t_room ***rooms, t_ant ***ants, char ***map,
															t_control *control)
{
	if (control->debug)
		ft_putchar('\n');
	ft_putstr("Map Error! There is no path to the end!\n");
	vanish_ant_farm(rooms, ants, map);
	exit(0);
}

static void		begin_computations(t_room ***rooms, t_ant ***ants, char ***map,
															t_control *control)
{
	*ants = summon_ants(control);
	control->start->occupant_count = control->ant_count;
	mark_shortest_path(control->end, control);
	if (control->debug)
		print_map_debug(*rooms);
	if (!control->found_path)
		no_path_error(rooms, ants, map, control);
	ft_print_tab(*map);
	ft_putchar('\n');
	ants_go_marching(*ants, control);
	vanish_ant_farm(rooms, ants, map);
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
		begin_computations(&rooms, &ants, &map, &control);
	else
		ft_putstr("Map Error!\n");
	return (0);
}
