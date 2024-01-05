/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:29:29 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 12:58:37 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ntpr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ntpr[i] == ' ' || (ntpr[i] >= '\t' && ntpr[i] <= '\r'))
		i++;
	if ((ntpr[i] == '-' || ntpr[i] == '+') && ft_isalnum(ntpr[i + 1]))
	{
		if (ntpr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ntpr[i] >= '0' && ntpr[i] <= '9')
	{
		result = result * 10 + (ntpr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char string[] = "  -+1234abcd";

	printf("%i\n", ft_atoi(string));
	printf("%i\n", atoi(string));
}*/
