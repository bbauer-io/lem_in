/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:00:37 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 18:45:41 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_int_sort takes an array of ints and returns a new array of those same ints
** but conveniently sorted from smallest to largest.
*/

static int		get_smallest_unused_int(int *arr, int *used, int len)
{
	int		i;
	int		smallest;
	int		sm_index;
	int		set;

	set = 0;
	i = 0;
	while (i < len)
	{
		if ((arr[i] < smallest || !set) && !used[i])
		{
			smallest = arr[i];
			sm_index = i;
			set = 1;
		}
		i++;
	}
	used[sm_index] = 1;
	return (smallest);
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

int				*ft_int_sort(int *arr, int len)
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
		sorted[i++] = get_smallest_unused_int(arr, used, len);
	free(used);
	return (sorted);
}
