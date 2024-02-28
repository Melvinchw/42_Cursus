/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:45:56 by mchua             #+#    #+#             */
/*   Updated: 2023/09/11 20:45:58 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && *s1)
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
