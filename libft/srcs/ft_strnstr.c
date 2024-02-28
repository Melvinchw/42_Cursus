/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:58:33 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:58:34 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *src, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	if (*substr == '\0')
		return ((char *)src);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (substr[j] == src[i + j] && (i + j) < len)
		{
			if (substr[j + 1] == '\0')
			{
				return ((char *)src + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
