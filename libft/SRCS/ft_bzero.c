/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:55:23 by mchua             #+#    #+#             */
/*   Updated: 2023/08/22 20:55:24 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		ft_memset(s[i], 0, n);
		i++;
	}
}
/*
int	main()
{
	char	s[20] = "Hello";
	
	printf("Original string is: %s\n", s);
	ft_bzero(s, 3);
	printf("Final string is: %s\n", s);
	return (0);
}
*/
