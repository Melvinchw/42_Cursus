/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexlu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:11:16 by mertan            #+#    #+#             */
/*   Updated: 2023/09/21 09:21:57 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_phexlu(unsigned int n, char c)
{
	char	*hexbase;
	int		count;

	if (c == 'x')
		hexbase = "0123456789abcdef";
	if (c == 'X')
		hexbase = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
	{
		ft_pchar(hexbase[n]);
		count++;
	}
	else
	{
		count += ft_phexlu(n / 16, c);
		count += ft_phexlu(n % 16, c);
	}
	return (count);
}
