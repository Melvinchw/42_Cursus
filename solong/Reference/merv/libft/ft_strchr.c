/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:30:06 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 09:22:34 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int main() 
{
    const char *str = "teste";
    int target = '\0';

    char *result1 = ft_strchr(str, target);
    char *result2 = strchr(str, target);

    if (result1 != NULL || result2 != NULL) 
    {
        printf("Character found: %c\n", *result1);
        printf("Character found: %c\n", *result2);
    } 
    else 
    {
        printf("Character not found\n");
    }

    return 0;
}
*/