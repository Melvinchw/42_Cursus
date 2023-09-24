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

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static void	ft_free_array(size_t i, char **array)
{
	while (i--)
	{
		free(array[i]);
	}
	free(array);
}

static char	**ft_split_string(const char *s, char c, char **arr, size_t wc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < wc)
	{
		while (s[j] && s[j] == c)
			j++;
		arr[i] = ft_substr(s, j, ft_word_length(&s[j], c));
		if (!arr[i])
		{
			ft_free_array(i, arr);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**buffer;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	buffer = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!buffer)
		return (NULL);
	buffer = ft_split_string(s, c, buffer, wc);
	return (buffer);
}
