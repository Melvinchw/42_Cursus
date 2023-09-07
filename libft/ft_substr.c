/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:35:38 by mchua             #+#    #+#             */
/*   Updated: 2023/09/07 20:35:39 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	string_len;
	char	*memory;
	size_t	i;
	
	string_len = ft_strlen ((char *)s);
	if (start >=  string_len || string_len == 0)
		return (NULL);
	memory = (char *)(malloc(sizeof (char) * (len + 1)));
	i = 0;
	if (memory == NULL)
		return (NULL);
	else
		while (i < len)
		{
			memory[i] = s[start];
			i++;
			start++;
		}
	memory[i] = '\0';
	return (memory);
}
/*
int main()
{
	char	*string;

	string = ft_substr("Hello", 5, 3);
	if (string != NULL)
	{
		printf("%s\n", string);
		free(string); // Don't forget to free the allocated memory when done
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	
	return (0);
}
*/
