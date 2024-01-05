/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:42:07 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 09:03:22 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stddef.h>
#include <stdio.h>
*/
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (!n || n <= len_dest)
		return (len_src + n);
	i = 0;
	while (src[i] && i < n - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	char	src[] = "World!";
	char	dest[100] = "Hello, ";

	printf("dest %s\n", dest);
	printf("%zu\n", ft_strlcat(dest, src, 2));
	printf("Updated dest: %s\n", dest);
}*/
