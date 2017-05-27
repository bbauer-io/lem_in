/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_read_results.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:22:34 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/26 14:45:08 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		print_read_results(t_room **rooms, t_control *control)
{
	ft_putstr("\n\nRooms!\n");
	while (rooms && *rooms)
	{
		ft_putstr((*rooms)->name);
		if ((*rooms)->is_end)
			ft_putstr("->E<-");
		if ((*rooms)->is_start)
			ft_putstr("->S<-");
		ft_printf(" (%d, %d)\n", (*rooms)->x_coord, (*rooms)->y_coord);
		rooms++;
	}
	ft_putstr("\nControl!\n");
	ft_printf("ant_count: %d\nstart: %p\nend: %p\nhas_tunnels: %d\nmap_has_anomaly: %d\n",
			control->ant_count, control->start, control->end, control->has_tunnels, control->map_has_anomaly);
}
