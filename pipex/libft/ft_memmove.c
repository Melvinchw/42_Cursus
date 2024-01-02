/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:55:54 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:55:55 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_buffer;
	unsigned char	*src_buffer;

	if (!dest && !src)
		return (NULL);
	dest_buffer = (unsigned char *)dest;
	src_buffer = (unsigned char *)src;
	if (dest_buffer < src_buffer)
	{
		while (len--)
			*(dest_buffer++) = *(src_buffer++);
	}
	else if (dest_buffer > src_buffer)
	{
		while (len--)
			dest_buffer[len] = src_buffer[len];
	}
	return (dest);
}
