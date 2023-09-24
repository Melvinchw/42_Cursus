/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:11:11 by mchua             #+#    #+#             */
/*   Updated: 2023/09/13 22:11:44 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	intcounter(int n)
{
	size_t	i;
	
	i = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		count;
	char		*str_num;
	long int	num;

	num = n;
	count = intcounter(n);
	if (n < 0)
	{
		num *= -1;
		count++;
	}
	str_num = (char *)malloc((sizeof (char) * count) + 1);
	if (str_num == NULL)
		return (NULL);
	str_num[count] = '\0';
	while (count > 0)
	{
		count--;
		str_num[count] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}
