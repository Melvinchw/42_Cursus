/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:18:29 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:18:30 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}