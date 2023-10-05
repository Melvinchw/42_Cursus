/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:20:08 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:20:10 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int					count;
	char				*list;
	unsigned long int	num;

	count = 0;
	num = n;
	if (c == 'x')
		list = "0123456789abcdef";
	else if (c == 'X')
		list = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += 1 + ft_puthex((num / 16), c);
		ft_putchar(list[num % 16]);
	}
	else
		count += ft_putchar(list[num % 16]);
	return (count);
}
