/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vanish_ant_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:59:26 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 06:41:12 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Frees an entire rooms list and any properties that have been malloced and
** attached to it.
*/

void			vanish_rooms(t_room ***rooms)
{
	t_room	**tmp;

	if (rooms && *rooms)
	{
		tmp = *rooms;
		while (**rooms)
		{
			if ((**rooms)->connections)
				free((**rooms)->connections);
			if ((**rooms)->name)
				ft_strdel(&(**rooms)->name);
			if ((**rooms)->commands)
				ft_tab_del(&(**rooms)->commands);
			while ((**rooms)->commands && (*(**rooms)->commands))
				ft_strdel(&(*(**rooms)->commands++));
			free(*((*rooms)++));
		}
		free(tmp);
		tmp = NULL;
	}
}

/*
** Frees the ants struct array, the map array, and the rooms array at the end
** of the program.
*/

void			vanish_ant_farm(t_room ***rooms, t_ant ***ants, char ***map)
{
	int		i;

	if (map && *map && **map)
		ft_tab_del(map);
	if (ants && *ants)
	{
		i = 0;
		while ((*ants)[i])
		{
			if ((*ants)[i]->name)
				ft_strdel(&(*ants)[i]->name);
			free((*ants)[i]);
			i++;
		}
		free(*ants);
		*ants = NULL;
	}
	if (rooms)
		vanish_rooms(rooms);
	*map = NULL;
	get_next_line(-42, NULL);
}
