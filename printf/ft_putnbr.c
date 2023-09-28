/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:19:15 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:19:23 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (n < 0)
	{
		num *= -1;
		ft_putchar('-');
		count += 1;
	}
	if (num >= 10)
	{
		count += 1 + ft_putnbr(num / 10);
		ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}
