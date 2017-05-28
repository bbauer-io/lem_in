/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 16:29:19 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** returns a copy of the queue table with the specified index removed.
** will probably always use index 0, but theres an option...
** frees the original table.
*/

t_room		**queue_rem_one(t_room **src, size_t rem)
{
	size_t		tab_len;
	t_room		**new_tab;

	tab_len = 0;
	while (src[tab_len])
		tab_len++;
	if (rem > tab_len)
		return (NULL);
	new_tab = (t_room **)malloc(sizeof(t_room *) * tab_len);
	new_tab[tab_len - 1] = NULL;
	ft_memcpy(new_tab, src, sizeof(t_room *) * rem);
	if (rem < tab_len)
		ft_memcpy(&new_tab[rem], &src[rem + 1],
										sizeof(t_room *) * (tab_len - rem - 1));
	new_tab[tab_len] = NULL;
	if (src)
		free(src);
	return (new_tab);
}
