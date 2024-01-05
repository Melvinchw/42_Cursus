/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:48:20 by mertan            #+#    #+#             */
/*   Updated: 2023/09/12 10:48:39 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
//Test function
void	uppercase(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	index++;
	index--;
}

int	main(void)
{
	char str[] = "hello, World";
	ft_striteri(str, uppercase);
	printf("%s\n", str);
}*/
