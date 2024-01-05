/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:50:42 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 15:21:33 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int	split_words(char **strs, char *str, char c)
{
	int	len;
	int	i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	*strs = malloc(sizeof(char) * (len + 1));
	if (!*strs)
		return (0);
	i = -1;
	while (++i < len)
		strs[0][i] = str[i];
	strs[0][i] = 0;
	return (1);
}

static void	*list_free(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**strs;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	strs = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !split_words(&strs[i++], str, c))
			return (list_free(strs, i));
		while (*str && *str != c)
			str++;
	}
	strs[i] = 0;
	return (strs);
}
/*
int	main(void)
{
	char const *input1 = "Hello,World,Split,Example";
	char delimiter1 = ',';
	char const *input2 = "   lorem g elit. Sed non risus. Suspendisse   ";
	char delimiter2 = ' ';
	char **result1 = ft_split(input1, delimiter1);
	char **result2 = ft_split(input2, delimiter2);
	if (!result1 || !result2)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Result 1:\n");
	for (int i = 0; result1[i]; i++)
		printf("%s\n", result1[i]);
	printf("Result 2:\n");
	for (int i = 0; result2[i]; i++)
		printf("%s\n", result2[i]);
	return 0;
}*/
