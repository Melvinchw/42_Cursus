/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:12:34 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:13:39 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	size_t	counter;

	ptr = lst;
	counter = 1;
	if (ptr == NULL)
		return (0);
	while (ptr -> next != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return ((int)counter);
}
