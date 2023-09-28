/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:22:43 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:22:44 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	ft_putvhex(unsigned long int n)
{
	int		count;
	char	*list;

	count = 0;
	list = "0123456789abcdef";
	if (n >= 16)
	{
		count += 1 + ft_putvhex(n / 16);
		ft_putchar(list[n % 16] + '0');
	}
	else
		count += ft_putchar(list[n % 16] + '0');
	return (count);
}

int	ft_putvoid(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putvhex(n);
	}
	return (count);
}
