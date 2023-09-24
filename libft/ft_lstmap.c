/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:12:12 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 10:12:16 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ptr;

	new_lst = NULL;
	ptr = NULL;
	while (lst != NULL)
	{
		if (f == NULL)
			ptr = ft_lstnew(lst -> content);
		else
			ptr = ft_lstnew(f(lst -> content));
		if (ptr == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, ptr);
		lst = lst -> next;
	}
	return (new_lst);
}
