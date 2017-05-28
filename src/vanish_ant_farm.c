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

static void		vanish_commands(t_com *commands)
{
	t_com	*tmp;

	while (commands)
	{
		tmp = commands->next;
		free(commands);
		commands = tmp;
		if (commands)
			tmp = commands->next;
	}
}

static void		vanish_rooms(t_room ***rooms)
{
	int		i;
	t_com	*tmp;

	if (rooms && *rooms)
	{
		i = 0;
		while (**rooms)
		{
			if ((**rooms)->connections)
				free((**rooms)->connections);
			if ((**rooms)->name)
				ft_strdel(&(**rooms)->name);
			tmp = ((**rooms)->commands;
			while ((**rooms)->commands && (*(**rooms)->commands))
				ft_strdel(&(*(**rooms)->commands++));
			free(*(*rooms)++);
		}
		free(*rooms);
		*rooms = NULL;
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
