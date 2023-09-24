/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:04:54 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:04:58 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				i;
	unsigned char	*mem;

	i = 0;
	mem = malloc(nmemb * size);
	if (!mem || mem == 0)
		return (NULL);
	ft_memset(mem, 0, nmemb * size);
	return (mem);
}
