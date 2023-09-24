/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:50:28 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 15:50:29 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"
#include "unistd.h"

int	ft_putchar(char c)
{
	int	count;
	
	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;
	
	count = 0;
	while (*str != '\0')
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int	count;
	
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

int	printformat(char specifier, va_list ap)
{
	int	count;
	
	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_putnbr(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;
	
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += printformat(*(++format), ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	return (count);
}

int main()
{
	int	count;
	
	count = 0;
	//ft_printf("%d\n",ft_printf("%c\n",' '));
	//ft_printf("%d\n",ft_printf("%s\n", "Hello"));
	count = ft_printf("%d\n", -123456);
	ft_printf("%d", count);
	return (0);
	
}
