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

void	push_swap(t_node *stack_a, t_node *stack_b)
{
	int		length;
	t_node	*min_node;

	length = find_stack_length(stack_a);
	if (length == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (length != 3)
			pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b)
	{
		initialize_node(stack_a, stack_b);
		perform_move(stack_a, stack_b);
	}
	find_current_pos(*stack_a);
	min_node = find_min(stack_a);
	if (min_node->below_mid)
		while (stack_a != min_node)
			rra(stack_a);
	else
		while (stack_a != min_node)
			ra(stack_a);
}

void	sort_three(t_node *stack)
{
	long	max_num;

	max_num == find_max(stack);
	if (stack == NULL)
		return ;
	if (stack->data == max_num)
		ra(stack);
	else if (stack->next->data == max_num)
		rra(stack);
	if (stack->data > stack->next->data)
		sa(stack);
}

void	initialize_node(t_node *stack_a, t_node *stack_b)
{
	find_current_pos(*stack_a);
	find_current_pos(*stack_b);
	find_target(stack_a, stack_b);
	find_price(stack_a, stack_b);
	find_cheapest(stack_a, stack_b);
}

void	perform_move(t_node *stack_a, t_node *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest_node(stack_b);
	if (!cheapest_node->below_mid && !cheapest_node->target->below_mid)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->below_mid && cheapest_node->target->below_mid)
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	continue_rotate(stack_a, cheapest_node->target, 'a');
	continue_rotate(stack_b, cheapest_node, 'b');
	pa(stack_a, stack_b);
}
