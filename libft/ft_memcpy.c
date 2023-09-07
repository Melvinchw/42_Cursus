/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:42:25 by mchua             #+#    #+#             */
/*   Updated: 2023/08/22 19:42:27 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;
	unsigned char	*d;
	const unsigned char	*s;
	
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

int	main()
{
	char	dest[20] = "Hello";
	char	src[20] = "fuck";
	
	printf("Original string is: %s\n", dest);
	printf("Final string is: %s\n", ((unsigned char	*)ft_memcpy(dest, src, 6)));
	return (0);
}
//why declared a pointer to the void pointer variables instead of just typecasting them?
//included != '\0' to stop it from overflowing in the event that 
