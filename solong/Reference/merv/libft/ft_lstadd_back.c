/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:09:38 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 12:31:04 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}
/*
Checking Valid Inputs:
if (lst && new): This part checks if both lst and new are not NULL (empty).
Adding the New Node to the Back:
if (*lst == NULL): This checks if the linked list is empty (i.e., the *lst 
pointer is NULL). If it is, it means there are no nodes in the list.
If the list is empty, it sets the *lst pointer to point to the new node, 
effectively making the new node the first and only node in the list.
else: If the list is not empty (there are existing nodes), it does
ft_lstlast(*lst)->next = new;: It uses a helper function called ft_lstlast 
(which you may have defined earlier; it's not shown in this code) to find the 
last node of the linked list. Then, it makes the last node's next pointer 
point to the new node, which effectively adds the new node to the end of the 
linked list.
*/
