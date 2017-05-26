/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:52:51 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/23 14:59:23 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_arr(int *arr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i < len - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putchar('\n');
}
