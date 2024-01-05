/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:41:56 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 09:08:31 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int main(void)
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, Universe!";

    int result1 = memcmp(str1, str2, 6);
    int result2 = memcmp(str1, str2, 8);

    printf("Comparison of first 6 characters: %d\n", result1);
    printf("Comparison of first 8 characters: %d\n", result2);

    int result3 = ft_memcmp(str1, str2, 6);
    int result4 = ft_memcmp(str1, str2, 8);

    printf("Comparison of first 6 characters: %d\n", result3);
    printf("Comparison of first 8 characters: %d\n", result4);

    return 0;
}*/
