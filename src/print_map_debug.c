/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:22:34 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 10:21:40 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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

void		print_map_debug(t_room **rooms, t_control *control)
{
	ft_putstr("\n\nRooms!\n");
	while (rooms && *rooms)
	{
		if ((*rooms)->is_end)
			ft_putstr("->E<-");
		if ((*rooms)->is_start)
			ft_putstr("->S<-");
		ft_putstr((*rooms)->name);
		ft_printf(" (%d, %d) ", (*rooms)->x_coord, (*rooms)->y_coord);
		if ((*rooms)->connections)
			print_connections((*rooms)->connections);
		else
			ft_putchar('\n');
		rooms++;
	}
	ft_putstr("\nControl!\n");
	ft_printf("ant_count: %d\nstart: %p\nend: %p\nhas_tunnels: %d\n",
		control->ant_count, control->start, control->end, control->has_tunnels);
	ft_printf("map_has_anomaly: %d\n", control->map_has_anomaly);
}
