/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:14:16 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/30 06:50:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Marks the steps to the exit on each room visited, and adds that rooms
** connections to the queue to be examined after everything at the current depth
** has been explored.
*/

static void		queue_connected(t_room *connected, t_room ***queue, int depth,
															t_control *control)
{
	if (!connected->steps_to_exit && !connected->is_end)
	{
		connected->steps_to_exit = depth;
		*queue = add_room(*queue, connected);
	}
	if (connected->is_start)
		control->found_path = 1;
}

/*
** Uses a breadth first search algorithm to find the shortest path from the room
** passed in (End) to the Start. Each room is marked with the number of steps
** we take from the exit. From the start we will be able to find the exit by
** always moving to a lower number. The lowest numbers available from each room
** represent the shortest path.
*/

void			mark_shortest_path(t_room *room, t_control *control)
{
	t_room		**queue;
	t_room		**next_queue;
	int			depth;
	int			i;
	int			k;

	queue = add_room(NULL, room);
	(*queue)->steps_to_exit = 0;
	depth = 1;
	while (queue && *queue)
	{
		next_queue = NULL;
		k = 0;
		while (queue[k])
		{
			i = 0;
			while (queue[k]->connections && queue[k]->connections[i])
				queue_connected(queue[k]->connections[i++], &next_queue, depth,
																	control);
			k++;
		}
		free(queue);
		queue = next_queue;
		depth++;
	}
}
