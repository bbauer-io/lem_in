/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:12:55 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 22:13:59 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Summons an array of ants from the netherworld.
*/

t_ant		**summon_ants(t_control *control)
{
	t_ant	**ants;
	int		serial_no;
	char	*stoa;

	if (!(ants = (t_ant **)malloc(sizeof(t_ant *) * (control->ant_count + 1))))
		return (NULL);
	ants[control->ant_count] = NULL;
	serial_no = 0;
	while (serial_no < control->ant_count)
	{
		if (!(ants[serial_no] = (t_ant *)malloc(sizeof(t_ant))))
			return (NULL);
		stoa = ft_itoa_base(serial_no, 16);
		ants[serial_no]->moving = 0;
		ants[serial_no]->serial = serial_no;
		ants[serial_no]->location = control->start;
		ants[serial_no]->name = ft_strnew(2 + ft_strlen(stoa));
		ft_strcat(ants[serial_no]->name, "Lx");
		ft_strcat(ants[serial_no]->name, stoa);
		ft_strdel(&stoa);
		serial_no++;
	}
	if (control->debug)
		print_ants_debug(ants);
	return (ants);
}
