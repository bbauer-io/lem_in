/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:31:35 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/24 21:33:21 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(char const *str)
{
	int		is_neg;
	long	nbr;

	is_neg = 0;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		is_neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += (*str - '0');
		str++;
	}
	if (is_neg)
		nbr *= -1;
	return (nbr);
}
