/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:35:38 by mchua             #+#    #+#             */
/*   Updated: 2023/09/07 20:35:39 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		string_len;
	char				*memory;
	size_t				i;

	string_len = ft_strlen ((char *)s);
	if (!s || start >= string_len || len == 0)
		return (ft_strdup(""));
	if (len > string_len - start)
		len = string_len - start;
	memory = (char *)(malloc(sizeof (char) * (len + 1)));
	i = 0;
	if (memory == NULL)
		return (NULL);
	while (i < len)
	{
		memory[i] = s[start];
		i++;
		start++;
	}
	memory[i] = '\0';
	return (memory);
}
