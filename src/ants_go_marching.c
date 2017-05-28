/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_marching.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:44:10 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 22:41:13 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		report_locations(t_ant **ants, t_control *control)
{
	int		multiple_moves;
	int		i;

	i = 0;
	multiple_moves = 0;
	while (i < control->ant_count)
	{
		if (ants[i]->moving)
		{
			if (multiple_moves)
				ft_putchar(' ');
			ft_printf("%s-%s", ants[i]->name, ants[i]->location->name);
			multiple_moves = 1;
			ants[i]->moving = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

static void		move_ant(t_ant *ant, t_room *move_to)
{
	ant->moving = 1;
	ant->location->occupant_count--;
	if (ant->location->occupant_count == 0)
		ant->location->is_occupied = 0;
	ant->location = move_to;
	ant->location->is_occupied = 1;
	ant->location->occupant_count++;
}

static t_room	*choose_best_move(t_ant *ant)
{
	int		shortest;
	t_room	*best_move;
	t_room	**paths;
	t_room	*path;

	shortest = INT_MAX;
	paths = ant->location->connections;
	best_move = NULL;
	path = *paths;
	while (path)
	{
		if (path->steps_to_exit < ant->location->steps_to_exit
											&& path->steps_to_exit < shortest)
			if (!best_move || best_move->steps_to_exit > path->steps_to_exit)
				if (!path->is_occupied || path->is_end)
				{
					shortest = path->steps_to_exit;
					best_move = path;
				}
		path = *(++paths);
	}
	return (best_move);
}

void			ants_go_marching(t_ant **ants, t_control *control)
{
	int		i;
	t_room	*best_move;

	while (control->end->occupant_count < control->ant_count)
	{
		i = 0;
		while (ants[i])
		{
			best_move = NULL;
			if (ants[i]->location != control->end)
				best_move = choose_best_move(ants[i]);
			if (best_move)
				move_ant(ants[i], best_move);
			i++;
		}
		report_locations(ants, control);
	}
	if (control->debug)
		ft_printf("Moved %d of %d ants to end.\n", control->end->occupant_count,
															control->ant_count);
}
