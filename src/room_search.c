/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:08:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/26 13:20:25 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Searches the room list one with a matchin name.
*/

t_room		*room_search(t_room **rooms, char *search)
{
	while (rooms && *rooms)
	{
		if (ft_strequ(search, (*rooms)->name))
			return (*rooms);
		rooms++;
	}
	return (NULL);
}

