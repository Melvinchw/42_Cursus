/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:50:30 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 11:58:08 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
Finding the Last Node:
The code uses a while loop to traverse through the linked list.
while (lst): This loop continues as long as the lst pointer is not NULL (
empty). It means it keeps going until it reaches the end of the linked list.

Inside the loop: if (!lst->next): This condition checks if the current node 
(lst) doesn't have a next node. In other words, it checks if it's the last 
node in the list. If it is the last node (i.e., there's no next node), the code 
returns the pointer to this last node using return (lst). This means it has 
found the last node and is done.

If it's not the last node, it moves to the next node by following the arrow 
(pointer) to the next box in the linked list: lst = lst->next;.

Returning the Last Node:
After the loop, if it hasn't found the last node, it means the linked list was 
empty (lst was initially NULL), so it returns whatever lst is at that point.
*/
