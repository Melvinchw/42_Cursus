/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:49:26 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 12:05:08 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/* 
Initializing a Counter; 
Counting the Nodes: 
while (lst): loop that continues as long as the lst 
pointer is not NULL until it reaches the end of the linked list. 
lst = lst->next; After counting a node, it moves to the next node by following 
the arrow (pointer) to the next box in the linked list. This process continues 
until it reaches the end. 
Returning the Size:
return (size);: Once the loop has counted all the nodes, it 
returns the final value of size, which represents the number of nodes in the 
linked list.
*/
