/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:21:09 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:21:10 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned long	num;
	int				count;

	num = n;
	count = 0;
	if (num >= 10)
	{
		count += 1 + ft_putunsigned(num / 10);
		ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}
