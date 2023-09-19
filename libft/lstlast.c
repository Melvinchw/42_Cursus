#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	
	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	return (ptr);
}
