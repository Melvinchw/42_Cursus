/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:50:57 by mertan            #+#    #+#             */
/*   Updated: 2023/09/20 10:58:57 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
