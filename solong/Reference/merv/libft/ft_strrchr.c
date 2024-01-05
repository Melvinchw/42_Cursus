/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:08:54 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 09:28:08 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)str + len);
		len--;
	}
	if (str[len] == c)
		return ((char *)str + len);
	return (NULL);
}
/*
int main( void )
{
    printf("%s\n", strrchr("abcdeabcde", 'g'));
    if (strrchr( "abcdeabcde", 'x' ) == NULL)
    	printf("NULL\n");
    printf("%s\n", ft_strrchr("abcdeabcde", 'g'));
    if (ft_strrchr( "abcdeabcde", 'x' ) == NULL)
    	printf("NULL\n");
    return EXIT_SUCCESS;
}*/
