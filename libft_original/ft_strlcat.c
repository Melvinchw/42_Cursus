/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:47:53 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:47:55 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	result;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size || size == 0)
		return (src_len + size);
	if (dest_len > size)
		result = size + src_len;
	else
		result = dest_len + src_len;
	src_len = 0;
	while (dest_len < size - 1 && src[src_len] != '\0')
		dest[dest_len++] = src[src_len++];
	dest[dest_len] = '\0';
	return (result);
}
