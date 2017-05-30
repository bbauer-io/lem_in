/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 07:07:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Prints a message a frees all allocated memory if a path cannot be found from
** end to start.
*/

static void		no_path_error(t_room ***rooms, t_ant ***ants, char ***map,
															t_control *control)
{
	if (control->debug)
		ft_putchar('\n');
	ft_putstr("Map Error! There is no path to the end!\n");
	vanish_ant_farm(rooms, ants, map);
	exit(0);
}

/*
** Main control structure. After our map has been determined to be valid,
** this function begins setting up to calculate the shortest path and from
** end to start, then moves the ants along that path and prints their locations
** as they move.
*/

static void		begin_computations(t_room ***rooms, t_ant ***ants, char ***map,
															t_control *control)
{
	*ants = summon_ants(control);
	control->start->occupant_count = control->ant_count;
	mark_shortest_path(control->end, control);
	if (control->debug)
		print_map_debug(*rooms);
	if (!control->found_path && control->start != control->end)
		no_path_error(rooms, ants, map, control);
	ft_print_tab(*map);
	ft_putchar('\n');
	ants_go_marching(*ants, control);
	vanish_ant_farm(rooms, ants, map);
}

/*
** Setup begins, a -v option is available for debugging which is parsed here.
** If the map is invalid, print an error message, otherwise we begin the main
** program with begin_computations().
*/

int				main(int argc, char **argv)
{
	t_control	control;
	t_room		**rooms;
	t_ant		**ants;
	char		**map;

	map = NULL;
	rooms = NULL;
	ants = NULL;
	ft_bzero(&control, sizeof(t_control));
	if (argc == 2 && **(++argv) == '-' && (*argv)[1] == 'v')
		control.debug = 1;
	if ((map = read_map(&rooms, &control, map)) && !control.map_has_anomaly
			&& control.ant_count > 0 && control.start && control.end)
		begin_computations(&rooms, &ants, &map, &control);
	else
		ft_putstr("Map Error!\n");
	return (0);
}
