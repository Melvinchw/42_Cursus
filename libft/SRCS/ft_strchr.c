/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:10:10 by mchua             #+#    #+#             */
/*   Updated: 2023/08/21 20:10:25 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (str++)
	{
		if (str == c)
			return (&str);
	}
	return (NULL);
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		printf("The first occurence of %c in %s is %s\n", argv[2][0], argv[1], ft_strchr(argv[1],argv[2][0]));
	}
	else
		printf("\n");
	return (0);
}
