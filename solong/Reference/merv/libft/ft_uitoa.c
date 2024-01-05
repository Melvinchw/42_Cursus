/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:15:13 by mertan            #+#    #+#             */
/*   Updated: 2023/09/20 12:23:36 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	unsigned long	nbr;

	nbr = n;
	len = ft_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_len(n));
}
