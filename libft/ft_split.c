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

static char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	unsigned int		string_len;
	char				*memory;
	size_t				i;

	string_len = ft_strlen ((char *)s);
	if (!s || start >= string_len || len == 0)
		return (NULL);
	if (len > string_len - start)
		len = string_len - start;
	memory = (char *)(malloc(sizeof (char) * (len + 1)));
	i = 0;
	if (memory == NULL)
		return (NULL);
	while (i < len)
	{
		memory[i] = s[start];
		i++;
		start++;
	}
	memory[i] = '\0';
	return (memory);
}
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	unsigned int	start;
	char	*str;
	char	**memory;

	i = 0;
	j = 0;
	str = (char *)s;
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
		memory[j] = ft_sub(s, start, (i - start));
		j++;
	}
	memory[j] = '\0';
	return (memory);
}
