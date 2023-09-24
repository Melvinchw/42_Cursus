#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	size_t	counter;

	ptr = lst;
	counter = 1;
	if (ptr == NULL)
		return (0);
	while (ptr -> next != NULL)
	{
		counter++;
		ptr = ptr->next;	
	}
	return ((int)counter);
}
