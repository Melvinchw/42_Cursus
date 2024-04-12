/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:35:51 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:35:51 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*ref;
	int		stack_size;

	stack_size = find_stack_length(stack);
	if (*stack == NULL || stack_size < 2)
		return ;
	ref = (*stack)->next;
	if (stack_size == 2)
		(*stack)->next = NULL;
	else
	{
		ref->next->prev = *stack;
		(*stack)->next = (*stack)->next->next;
	}
	(*stack)->prev = ref;
	ref->prev = NULL;
	ref->next = *stack;
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
