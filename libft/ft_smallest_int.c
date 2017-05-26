/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:44:28 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 11:01:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the index of the smallest int found in an array of specified size.
*/

int		ft_smallest_int(int *arr, int size)
{
	int		smallest;
	int		sm_index;
	int		i;

	smallest = arr[0];
	sm_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			sm_index = i;
		}
		i++;
	}
	return (sm_index);
}
