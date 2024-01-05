/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:39:13 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 14:50:15 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchar(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	start = 0;
	while (s1[start] && ft_strchar(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (ft_strchar(s1[end - 1], set) && end != start)
		end--;
	res = malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 1);
	return (res);
}
/*
int	main(void)
{
	char const *s1 = "  aHello, World!b   ";
	char const *set = "ab ";
	char *trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str)
	{
		printf("Original string: '%s'\n", s1);
		printf("Trimmed string:  '%s'\n", trimmed_str);
		free(trimmed_str);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/
