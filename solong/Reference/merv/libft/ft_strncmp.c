/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:30:04 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 09:29:20 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((i < n - 1) && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include<string.h>
int main( void )
{
	printf( "%d\n", strncmp( "abcDef", "abcdEF", 10 ) );
	printf( "%d\n", strncmp( "abcdef", "abcDEF",  6 ) );
	printf( "%d\n", strncmp( "abcdef", "abcDEF",  3 ) );
	printf( "%d\n", strncmp( "abcdef", "abcDEF",  0 ) );

	printf( "%d\n", ft_strncmp( "abcDef", "abcdEF", 10 ) );
	printf( "%d\n", ft_strncmp( "abcdef", "abcDEF",  6 ) );
	printf( "%d\n", ft_strncmp( "abcdef", "abcDEF",  3 ) );
	printf( "%d\n", ft_strncmp( "abcdef", "abcDEF",  0 ) );
	
	return EXIT_SUCCESS;
}*/
