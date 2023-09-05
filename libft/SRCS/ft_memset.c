/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:31:21 by mchua             #+#    #+#             */
/*   Updated: 2023/08/21 22:11:22 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*s, int c, size_t n)
{
	size_t	i;
	
	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char str[20] = "Hello, World!";
	printf("Before memset: %s\n", str);
	printf("After memset: %s\n", ((char *)ft_memset(str, '*', 3)));
	return (0);
}
// Default memset is void *, to print, need to typecast.
//using char *str gives undefined behaviour as 'string literal' is read only.*/
