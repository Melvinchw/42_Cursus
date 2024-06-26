/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:34:55 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:34:55 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_current_pos(t_node **stack)
{
	int		i;
	int		midpoint;
	t_node	*ref;

	ref = *stack;
	i = 0;
	midpoint = find_stack_length(stack) / 2;
	while (ref)
	{
		(ref)->current_pos = i;
		if (i > midpoint)
			ref->below_mid = true;
		else
			ref->below_mid = false;
		ref = ref->next;
		i++;
	}
}

void	find_target(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_stack_a;
	t_node	*target_node;
	long	best_target;

	while (stack_b)
	{
		target_node = NULL;
		best_target = LONG_MAX;
		current_stack_a = stack_a;
		while (current_stack_a)
		{
			if (current_stack_a->data > stack_b->data
				&& current_stack_a->data < best_target)
			{
				best_target = current_stack_a->data;
				target_node = current_stack_a;
			}
			current_stack_a = current_stack_a->next;
		}
		if (best_target != LONG_MAX)
			stack_b->target = target_node;
		else
			(stack_b)->target = find_min_node(stack_a);
		stack_b = stack_b->next;
	}
}

void	find_price(t_node *stack_a, t_node *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = find_stack_length(&stack_a);
	stack_b_len = find_stack_length(&stack_b);
	while (stack_b)
	{
		if (stack_b->below_mid)
			stack_b->cost = stack_b_len - (stack_b->current_pos);
		else
			stack_b->cost = stack_b->current_pos;
		if (stack_b->target->below_mid)
			stack_b->cost += stack_a_len - (stack_b->target->current_pos);
		else
			stack_b->cost += stack_b->target->current_pos;
		stack_b = stack_b->next;
	}
}

void	find_cheapest(t_node *stack_b)
{
	long	best_price;
	t_node	*best_node;

	best_price = LONG_MAX;
	if (stack_b == NULL)
		return ;
	while (stack_b)
	{
		if (stack_b->cost < best_price)
		{
			best_node = stack_b;
			best_price = stack_b->cost;
		}
		stack_b = stack_b->next;
	}
	best_node->cheapest = true;
}

t_node	*get_cheapest_node(t_node *stack_b)
{
	t_node	*ref_node;

	ref_node = stack_b;
	while (ref_node)
	{
		if (ref_node->cheapest)
			return (ref_node);
		ref_node = ref_node->next;
	}
	return (NULL);
}
