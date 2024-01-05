/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:59 by mertan            #+#    #+#             */
/*   Updated: 2023/09/06 17:59:28 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)dest;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (dest);
}
