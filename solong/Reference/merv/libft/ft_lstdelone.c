/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:32:33 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 12:59:30 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
Checking Valid Inputs:
if (lst && new): This part checks if both lst and new are not NULL (empty). 
It's important to ensure that we have valid input data before proceeding.
Adding the New Node to the Back:
if (*lst == NULL): This checks if the linked list is empty (i.e., the *lst 
pointer is NULL). If it is, it means there are no nodes in the list.
If the list is empty, it sets the *lst pointer to point to the new node, 
effectively making the new node the first and only node in the list.
else: If the list is not empty (there are existing nodes), it does the 
following: 
ft_lstlast(*lst)->next = new;: It uses a helper function called ft_lstlast 
(which you may have defined earlier; it's not shown in this code) to find the 
last node of the linked list. Then, it makes the last node's next pointer 
point to the new node, which effectively adds the new node to the end of 
the linked list.
*/
