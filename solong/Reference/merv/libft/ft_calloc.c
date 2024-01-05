/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:59:11 by mertan            #+#    #+#             */
/*   Updated: 2023/09/11 13:18:45 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	if (num_elements == 0 || element_size == 0)
	{
		num_elements = 0;
		element_size = 1;
	}
	ptr = malloc(num_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
/*
#include <assert.h>
int	main(void)
{
	printf("Test case 1: Allocating memory for an array of integers\n");
	size_t num_elements = 5;
	size_t element_size = sizeof(int);
	int *arr_ft_calloc = (int *)ft_calloc(num_elements, element_size);
	int *arr_calloc = (int *)calloc(num_elements, element_size);
	assert(memcmp(arr_ft_calloc, arr_calloc, num_elements * element_size) == 0);
	free(arr_ft_calloc);
	free(arr_calloc);
}*/
