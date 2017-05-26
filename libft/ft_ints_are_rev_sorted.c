/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints_are_rev_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:45:12 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 20:32:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if the array is sorted from largest to smallest.
*/

int		ft_ints_are_rev_sorted(int *ints, int len)
{
	int		i;

	if (len == 1)
		return (1);
	i = 1;
	while (i < len)
	{
		if (ints[i - 1] <= ints[i])
			return (0);
		i++;
	}
	return (1);
}
