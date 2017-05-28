/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vanish_ant_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:59:26 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 22:24:13 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		vanish_rooms(t_room ***rooms)
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
}
