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
	write(1, &c, 1);
	return (1);
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

int	ft_puthex(unsigned int n, char c)
{
	int	count;
	char	*list;
	unsigned long	num;
	
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

int	ft_putunsigned(unsigned int n)
{
	unsigned long	num;
	int	count;
	
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

int	printformat(char specifier, va_list ap)
{
	int	count;
	
	count = 0;
	
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunsigned(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')//when this format specifier is below, undefined behaviour found
		count += ft_putchar('%');
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
			format++;
			count += printformat(*format, ap);
		}
		else
		{
			count += ft_putchar(*format);
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
	//count = ft_printf("%d\n", -123456);
	count += ft_printf("%u", -123);
	ft_printf("\n%d\n", count);
	printf("%%");
	return (0);
	
}
