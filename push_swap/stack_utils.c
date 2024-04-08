/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:49:30 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:49:30 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*stack_tail(t_node *stack_a)
{
	t_node	*tail;

	while (stack_a->next != NULL)
		tail = stack_a->next;
	return (tail);
}

void	add_stack(t_node *stack_a, int nbr, char **argv)
{
	t_node	*new_stack;
	t_node	*ref;

	new_stack = mallloc(sizeof(t_node));
	if (!new_stack)
		handle_error(3, "Unable to allocate memory for stack!");
	if (stack_a == NULL)
	{
		stack_a = new_stack;
		stack_a->next = NULL;
		stack_a->prev = NULL;
		stack_a->data = nbr;
	}
	else
	{
		ref = stack_tail(stack_a);
		ref->next = new_stack;
		new_stack->prev = ref;
	}
}

void	stack_init(t_node *stack_a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		if (!correct_input(argv[i]))
			handle_error(2, "Incorrect inputs!\n", argv);
		nbr = convert_number(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			handle_error(2, "Values out of range!\n", argv);
		if (is_duplicate(stack_a, nbr))
		{
			handle_error(2, "Duplicates found!\n", argv);
			free_node(stack_a);
		}
		add_stack(stack_a, nbr, NULL);
		i++;
	}
}
