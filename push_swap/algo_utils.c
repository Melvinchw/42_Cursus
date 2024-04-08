/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:30:06 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:30:06 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_both(t_node *stack_a, t_node *stack_b, t_node *cheapest_node)
{
	while (stack_a != stack_b->target && stack_b != cheapest_node)
		r_both(stack_a, stack_b);
	find_current_pos(*stack_a);
	find_current_pos(*stack_b);
}

void	reverse_rotate_both(t_node *stack_a, t_node *stack_b,
							t_node *cheapest_node)
{
	while (stack_a != stack_b->target && stack_b != cheapest_node)
		rr_both(stack_a, stack_b);
	find_current_pos(*stack_a);
	find_current_pos(*stack_b);
}

void	continue_rotate(t_node **stack, t_node *node_on_top, char c)
{
	while (*stack != node_on_top)
	{
		if (c == 'a')
		{
			if (node_on_top->below_mid)
				rra(stack);
			else
				ra(stack);
		}
		else if (c == 'b')
		{
			if (node_on_top->below_mid)
				rra(stack);
			else
				ra(stack);
		}
	}
}

t_node	*find_min_node(t_node *stack)
{
	long	min_num;
	t_node	*min_node;

	min_num = LONG_MAX;
	if (stack == NULL)
		return ;
	while (stack)
	{
		if (stack->data < min_num)
		{
			min_num = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

long	find_max_num(t_node *stack)
{
	long	max_num;

	max_num = LONG_MIN;
	if (stack == NULL)
		return ;
	while (stack)
	{
		if (stack->data > max_num)
			max_num = stack->data;
		stack = stack->next;
	}
	return (max_num);
}
