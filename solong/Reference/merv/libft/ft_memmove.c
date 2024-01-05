/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:12:51 by mertan            #+#    #+#             */
/*   Updated: 2023/09/06 19:28:20 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d == s || !n)
		return (d);
	if (d < s)
		return (ft_memcpy(d, s, n));
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n -1];
			n--;
		}
	}
	return (dest);
}
