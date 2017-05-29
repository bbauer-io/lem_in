/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:22:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/26 13:21:17 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Checks that a string contains only digits up to the null terminator. Returns
** 0 if it finds any other characters. checks n characters of the string unless
** n is < 1 in which case it checks the entire string.
*/

int				line_is_numeric(char *line)
{
	while (line && *line)
		if (!ft_isdigit(*(line++)))
			return (0);
	return (1);
}

/*
** add_room copies src_tab to a new table with space for one more entry,
** then copies that entry and adds a pointer to it in the new table.
** Returns the new (char **) table.
*/

t_room			**add_room(t_room **src_tab, t_room *new_item)
{
	int		tab_len;
	t_room	**new_tab;

	tab_len = 0;
	while (src_tab && src_tab[tab_len])
		tab_len++;
	new_tab = (t_room **)malloc(sizeof(t_room *) * (tab_len + 2));
	ft_bzero(new_tab, sizeof(t_room *) * (tab_len + 2));
	ft_memcpy(new_tab, src_tab, sizeof(t_room *) * tab_len);
	new_tab[tab_len] = new_item;
	new_tab[++tab_len] = NULL;
	//vanish_rooms(&src_tab);
	return (new_tab);
}
