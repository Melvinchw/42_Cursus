#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;
	
	ptr = lst;
	if (lst != NULL && f != NULL)
	{
		while (ptr != NULL)
		{
			f(ptr -> content);
			ptr = ptr -> next;
		}
	}
}
