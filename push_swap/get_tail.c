t_node	*get_tail(t_node *stack_a)
{
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}