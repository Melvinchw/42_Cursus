/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:55:59 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:55:59 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*ref;
	t_node	*new_b;

	if (stack_a == NULL)
		return ;
	ref = stack_a;
	stack_a = ref->next;
	if (stack_b == NULL)
	{
		stack_b = ref;
		stack_b->next = NULL;
	}
	else
	{
		new_b = ref;
		stack_b->prev = new_b;
		new_b->next = stack_b;
		stack_b = new_b;
	}
	stack_a->prev = NULL;
	stack_b->prev = NULL;
}

void	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*ref;
	t_node	*new_a;

	if (stack_b == NULL)
		return ;
	ref = stack_b;
	stack_b = ref->next;
	if (stack_a == NULL)
	{
		stack_a = ref;
		stack_b->next = NULL;
	}
	else
	{
		new_a = ref;
		stack_a->prev = new_a;
		new_a->next = stack_a;
		stack_a = new_a;
	}
	stack_a->prev = NULL;
	stack_b->prev = NULL;
}

int	count_stack(t_node *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (i);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
