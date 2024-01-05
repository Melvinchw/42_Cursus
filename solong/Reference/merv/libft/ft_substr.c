/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:44 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 14:01:52 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		slen;

	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
	{
		sub = (char *)malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if (start + len > slen)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
int main()
{
    const char *str = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;

    char *substr = ft_substr(str, start, len);

    if (substr)
    {
        printf("Original String: %s\n", str);
        printf("Substring: %s\n", substr);
        free(substr);
    }
    else
        printf("Substring creation failed (NULL returned).\n");
    return 0;
}*/
