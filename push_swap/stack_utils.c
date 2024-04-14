/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:34:26 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:34:26 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*stack_tail(t_node **stack_a)
{
	t_node	*tail;

	tail = *stack_a;
	if (!tail)
		return (NULL);
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

void	add_stack(t_node **stack_a, int nbr, char **argv)
{
	t_node	*new_stack;
	t_node	*ref;

	new_stack = calloc(1, sizeof(t_node));
	if (!new_stack)
		handle_error(3, "Unable to allocate memory for stack!", argv);
	new_stack->data = nbr;
	new_stack->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_stack;
		(*stack_a)->prev = NULL;
	}
	else
	{
		ref = stack_tail(stack_a);
		ref->next = new_stack;
		new_stack->prev = ref;
	}
}

void	stack_init(t_node **stack_a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		if (!correct_input(argv[i]))
			handle_error(1, "Incorrect inputs!\n", argv);
		nbr = convert_number(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			handle_error(1, "Values out of range!\n", argv);
		if (is_duplicate(*stack_a, nbr))
		{
			handle_error(1, "Duplicates found!\n", argv);
			if (stack_a)
				free_stack(stack_a);
		}
		add_stack(stack_a, nbr, NULL);
		i++;
	}
}
