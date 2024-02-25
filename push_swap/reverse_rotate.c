#include <stdio.h>
#include <stdlib.h>

void	reverse_rotate(t_node **stack_a)
{
	t_node	*tail;
	t_node	*ref;

	tail = get_tail(*stack_a);
	ref = tail;
	tail->prev = tail->prev->prev;
	tail = ref->prev;
	tail->next = NULL;
	ref->next = *stack_a;
	(*stack_a)->prev = ref;
	(*stack_a) = ref;
	(*stack_a)->prev = NULL;
}
