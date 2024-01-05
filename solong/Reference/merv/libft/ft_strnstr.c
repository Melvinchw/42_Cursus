/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:55:44 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 12:40:03 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && i + j < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
    const char *largestring = "lorem ipsum ipsumm dolor sit amet";
    const char *smallstring = "ipsumm";
    char *ptr1;
    char *ptr2;

    ptr1 = strnstr(largestring, smallstring, 30);
    ptr2 = ft_strnstr(largestring, smallstring, 30);

    if (ptr1 != NULL)
        printf("'%s' found at position %s\n", smallstring, ptr1);
    else
        printf("'%s' not found in the string.\n", smallstring);

    if (ptr2 != NULL)
        printf("'%s' found at position %s\n", smallstring, ptr2);
    else
        printf("'%s' not found in the string.\n", smallstring);
    return 0;
}*/