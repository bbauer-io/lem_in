/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:31:15 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/09 15:33:05 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of entries in a char ** table.
*/

int			ft_tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}
