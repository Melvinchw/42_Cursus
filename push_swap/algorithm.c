/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:29:08 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:29:08 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_node **stack)
{
	long	max_num;
	t_node	*ref;

	ref = *stack;
	max_num = find_max_num(&ref);
	if ((*stack)->data == max_num)
		ra(stack);
	else if ((*stack)->next->data == max_num)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	stack_length;

	stack_length = find_stack_length(stack_a);
	while (stack_length > 3)
	{
		initialize_node(stack_a, stack_b);
		continue_rotate(stack_a, find_min_node(*stack_a), 'a');
		pb(stack_a, stack_b);
		stack_length = find_stack_length(stack_a);
	}
}

void	initialize_node(t_node **stack_a, t_node **stack_b)
{
	find_current_pos(stack_a);
	find_current_pos(stack_b);
	find_target(*stack_a, *stack_b);
	find_price(*stack_a, *stack_b);
	find_cheapest(*stack_b);
}

void	perform_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_b);
	if (!(cheapest_node->below_mid) && !(cheapest_node->target->below_mid))
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->below_mid && cheapest_node->target->below_mid)
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	continue_rotate(stack_a, cheapest_node->target, 'a');
	continue_rotate(stack_b, cheapest_node, 'b');
	pa(stack_b, stack_a);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	if (find_stack_length(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		while (find_stack_length(stack_a) > 3)
			pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		initialize_node(stack_a, stack_b);
		perform_move(stack_a, stack_b);
	}
	//find_current_pos(stack_a);
	if (find_min_node(*stack_a)->below_mid)
		while (*stack_a != find_min_node(*stack_a))
			rra(stack_a);
	else
		while (*stack_a != find_min_node(*stack_a))
			ra(stack_a);
}
