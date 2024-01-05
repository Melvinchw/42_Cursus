/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:53:55 by mertan            #+#    #+#             */
/*   Updated: 2023/09/13 11:11:31 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* t_list *ft_lstnew(void *content): creating a new function called ft_lstnew
   that takes something (which can be anything) as content and returns a t_list 
   box. node = malloc(sizeof(t_list)); making a new box (like the one in the 
   chain) and allocate right size memory right to hold a t_list box. if (!node) 
   return (NULL); checks if we got the memory for the box. If not, return NULL. 
   node->content = content;take the content you gave us and put it inside the 
   box. node->next = NULL; this box is the last one in the chain, so it doesn't 
   point to any other box. return (node); return new box.*/
