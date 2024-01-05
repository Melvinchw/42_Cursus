/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:24:16 by mertan            #+#    #+#             */
/*   Updated: 2023/09/20 12:42:47 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pnbr(unsigned long n)
{
	char	*hexbase;
	int		count;

	hexbase = "0123456789abcdef";
	count = 0;
	if (n < 16)
	{
		ft_pchar(hexbase[n]);
		count++;
	}
	else
	{
		count += ft_pnbr(n / 16);
		count += ft_pnbr(n % 16);
	}
	return (count);
}

int	ft_pptr(unsigned long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_pchar('0');
	ft_pchar('x');
	return (ft_pnbr(n) + 2);
}
