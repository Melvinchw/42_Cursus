#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	if (*lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			ptr = (*lst) -> next;
			del((*lst) -> content);
			free(*lst);
			*lst = ptr;
		}
	}
}
