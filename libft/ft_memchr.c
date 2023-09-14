/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:47 by mchua             #+#    #+#             */
/*   Updated: 2023/08/22 20:32:48 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const char *)s)[i] != c)
			i++;
		else
			return ((void *)s + i);
	}
	return (NULL);
}
/*
int main()
{
	char	s[20] = "Hello";
	char	c = 'e';
	void	*results = (ft_memchr(s, c, 3));
	
	if (results != NULL)
	{
		//size_t index = ((unsigned char *)results) - ((unsigned char *)s);
		printf("The value is found at index: %p\n", results);
	}
	else
		printf("The value is not found");
	return (0);
}*/
//return value is typecasted as the initial function is a void pointer.
//what is the use for memchr
//what does memchr output when tested
//find out about format specifier
