/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:16:35 by mchua             #+#    #+#             */
/*   Updated: 2023/09/07 21:16:36 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int	i;
	int	j;
	int	total_len;
	int	len1;
	int	len2;
	
	i = 0;
	j = 0;
	len1 = strlen((char *)s1);
	len2 = strlen((char *)s2);
	total_len = len1 + len2;
	new_string = (char *)malloc(sizeof (char) * (total_len + 1));

	if (new_string == NULL)
		return (NULL);
	else
		while (i < len1)
		{
			new_string[i] = s1[i];
			i++;
		}
		while (j < len2)
		{
			new_string[i] = s2[j];
			j++;
		}
	new_string[total_len] = '\0';
	return (new_string);
}
