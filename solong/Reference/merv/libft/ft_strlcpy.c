/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:33:27 by mertan            #+#    #+#             */
/*   Updated: 2023/09/07 11:40:15 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>
#include <stdio.h>
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!n)
		return (ft_strlen(src));
	i = 0;
	while ((i < n - 1) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main() 
{
    char	src[] = "Hello, World!";
    char	dest[15];
    unsigned int	size = ft_strlcpy(dest, src, sizeof(dest));

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    printf("Copied Size: %u\n", size);

    return (0);
}*/
