/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:10:02 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:38:16 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target && *stack_b != cheapest_node)
		r_both(stack_a, stack_b);
	find_current_pos(stack_a);
	find_current_pos(stack_b);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
							t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target && *stack_b != cheapest_node)
		rr_both(stack_a, stack_b);
	find_current_pos(stack_a);
	find_current_pos(stack_b);
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
				rrb(stack);
			else
				rb(stack);
		}
	}
}
