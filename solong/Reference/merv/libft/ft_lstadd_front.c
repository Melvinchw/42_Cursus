/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:09:06 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 12:04:47 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
Checking for Valid Inputs:
if (lst && new): This part checks if both lst and new are not NULL (empty).
Adding the New Node to the Front:
new->next = *lst;: Here, we set the next pointer of the new node to point to 
the current first node of the list. This step makes the new node the new first 
node in the list.
*lst = new;: Next, we update the *lst pointer (the pointer to the first node 
of the list) to point to the new node. This step officially makes the new node 
the first node in the list.
*/
