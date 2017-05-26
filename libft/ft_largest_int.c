/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:44:28 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 17:36:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the index of the largest int found in an array of specified size.
*/

int		ft_largest_int(int *arr, int size)
{
	int		largest;
	int		lg_index;
	int		i;

	largest = arr[0];
	lg_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] > largest)
		{
			largest = arr[i];
			lg_index = i;
		}
		i++;
	}
	return (lg_index);
}
