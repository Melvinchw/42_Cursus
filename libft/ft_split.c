/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:55:40 by mchua             #+#    #+#             */
/*   Updated: 2023/09/13 21:56:25 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_counter(char *str, char c)
{
	size_t	counter;
	size_t	flag;

	flag = 0;
	counter = 0;
	while (*str)
	{
		if (flag == 0 && *str != c)
		{
			flag = 1;
			counter++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	unsigned int	start;
	char	*str;
	char	**memory;

	i = 0;
	j = 0;
	str = s;
	memory = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));

	if (memory == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		while(s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		len = i - start;
		memory[j] = ft_substr(s, start, len);
		j++;
	}
	memory[j] = '\0';
	return (memory);
}
