/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:02:34 by mertan            #+#    #+#             */
/*   Updated: 2023/09/20 09:18:49 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_type(char c, va_list args, int *i)
{
	if (c == 'd' || c == 'i')
		return (ftp_itoa(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(args, unsigned int)));
	else if (c == 'c')
		return (ft_pchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_pstring(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_phexlu(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_pptr(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_pchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			count += check_type(input[i], args, &i);
			i++;
		}
		else
		{
			count += ft_pchar(input[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", -1);
	ft_printf("%d\n", -1);

	return 0;
}*/
