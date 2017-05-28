/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vanish_ant_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:59:26 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 18:35:09 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		vanish_rooms(t_room ***rooms)
{
	if (*rooms)
	{
		while (**rooms)
		{
			if ((**rooms)->connections)
				free((**rooms)->connections);
			if ((**rooms)->occupant)
				free((**rooms)->occupant);
			if ((**rooms)->name)
				free((**rooms)->name);
			while((**rooms)->commands && (*(**rooms)->commands))
				free((*(**rooms)->commands++));
			free(*(*rooms)++);
		}
		free(*rooms);
	}
}

void			vanish_ant_farm(t_room ***rooms, t_ant ***ants, char ***map)
{
	if (map && *map && **map)
		ft_tab_del(map);
	if (ants && *ants)
	{
		while (**ants)
		{
			if ((**ants)->name)
				free((**ants)->name);
			free(*(ants++));
		}
		free(*ants);
	}
	if (rooms)
		vanish_rooms(rooms);
	*map = NULL;
	*ants = NULL;
	*rooms = NULL;
}
