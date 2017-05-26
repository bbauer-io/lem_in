/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:17:43 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/26 10:21:11 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}
