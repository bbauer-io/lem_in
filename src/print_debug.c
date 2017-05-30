/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:22:34 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 06:39:33 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Prints the rooms that are connected to a given room.
*/

static void	print_connections(t_room **tmp)
{
	ft_putstr("Connected to: ");
	while (tmp && *tmp)
	{
		ft_putstr((*tmp)->name);
		++tmp;
		if (*tmp)
			ft_putstr(", ");
		else
			ft_putchar('\n');
	}
}

/*
** Prints some basic info about the map, which room is start and end, and how
** many steps that room is from the exit (that info won't be available until
** after it has been calculated, obviously).
*/

void		print_map_debug(t_room **rooms)
{
	ft_putstr("\nDEBUG INFO\n\nRooms:\n");
	while (rooms && *rooms)
	{
		ft_putstr((*rooms)->name);
		ft_printf(" (%d, %d) ", (*rooms)->x_coord, (*rooms)->y_coord);
		if ((*rooms)->is_end)
			ft_putstr("||--->END<---|| ");
		if ((*rooms)->is_start)
			ft_putstr("||-->START<--|| ");
		ft_printf("Steps to exit: %d ", (*rooms)->steps_to_exit);
		if ((*rooms)->connections)
			print_connections((*rooms)->connections);
		else
			ft_putstr("NO connections\n");
		rooms++;
	}
}

/*
** Prints the info saved in the control struct.
*/

void		print_control_debug(t_control *control)
{
	ft_putstr("\nControl Struct:\n");
	ft_printf("ant_count: %d\nstart: %p\nend: %p\nhas_tunnels: %d\n",
		control->ant_count, control->start, control->end, control->has_tunnels);
	ft_printf("map_has_anomaly: %d\n\n", control->map_has_anomaly);
}

/*
** Prints the names of all the ants that have been created.
*/

void		print_ants_debug(t_ant **ants)
{
	ft_putstr("\nSummoned Ants: \n");
	while (ants && *ants)
	{
		ft_putstr((*ants)->name);
		ft_putchar('\n');
		ants++;
	}
}
