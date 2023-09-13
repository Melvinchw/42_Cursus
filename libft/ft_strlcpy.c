/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:28:51 by mchua             #+#    #+#             */
/*   Updated: 2023/09/13 22:28:58 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlcpy(char *src, char *dst, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[i] != '\0')
		count++;
	if (size < 0)
		return (count);
	while (src[i] != '\0' && size > i - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
