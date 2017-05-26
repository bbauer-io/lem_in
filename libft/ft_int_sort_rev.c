/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:00:37 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 18:53:14 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_int_sort takes an array of ints and returns a new array of those same ints
** but conveniently sorted from smallest to largest.
*/

static int		get_largest_unused_int(int *arr, int *used, int len)
{
	int		i;
	int		largest;
	int		lg_index;
	int		set;

	set = 0;
	i = 0;
	while (i < len)
	{
		if ((arr[i] > largest || !set) && !used[i])
		{
			largest = arr[i];
			lg_index = i;
			set = 1;
		}
		i++;
	}
	used[lg_index] = 1;
	return (largest);
}

static int		all_used(int *used, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (used[i++] == 0)
			return (0);
	return (1);
}

int				*ft_int_sort_rev(int *arr, int len)
{
	int		i;
	int		*sorted;
	int		*used;

	sorted = (int *)malloc(sizeof(int) * len);
	used = (int *)malloc(sizeof(int) * len);
	ft_bzero(sorted, sizeof(int) * len);
	ft_bzero(used, sizeof(int) * len);
	i = 0;
	while (!all_used(used, len))
		sorted[i++] = get_largest_unused_int(arr, used, len);
	free(used);
	return (sorted);
}
