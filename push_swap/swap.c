/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:52:04 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:52:04 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*ref;
	int		stack_size;

	ref = *stack;
	stack_size = count_stack(&ref);
	if (*stack == NULL || stack_size < 2)
		return ;
	ref = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	ref->next = (*stack);
	ref->next->prev = ref;
	ref->next->next->prev = (*stack);
	ref->next->next->next = NULL;
	ref->prev = NULL;
	*stack = ref;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	s_both(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
