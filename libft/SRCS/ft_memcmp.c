/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:31:31 by mchua             #+#    #+#             */
/*   Updated: 2023/08/21 20:31:33 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	const char *x;
	const char *y;
	
	x = s1;
	y = s2;
	i = 0;
	while (i < n)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}

int	main()
{
	char	s1[20] = "Hello";
	char	s2[20] = "Hellp";

	if (ft_memcmp(s1, s2, 5) > 0)
		printf("This is larger");
	else if (ft_memcmp(s1, s2, 5) < 0)
		printf("This is smaller");
	else
		printf("Equal");
	return (0);
}
