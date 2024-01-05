/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:19:20 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 13:33:58 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
        char    *original = "Hello, world!";
        char    *duplicate1 = ft_strdup(original);
        char    *duplicate2 = strdup(original);

        if (duplicate1)
        {
                printf("Original: %s\n", original);
                printf("Duplicate: %s\n", duplicate1);
                free(duplicate1);
        }
        else
                printf("Memory allocation failed.\n");
        return (0);

        if (duplicate2)
        {
                printf("Original: %s\n", original);
                printf("Duplicate: %s\n", duplicate2);
                free(duplicate2);
        }
        else
                printf("Memory allocation failed.\n");
        return (0);
}*/
