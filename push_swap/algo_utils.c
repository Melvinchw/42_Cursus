/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:36:19 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:36:19 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_stack_length(t_node **stack)
{
	int		i;
	t_node	*ref;

	ref = *stack;
	i = 0;
	while (ref)
	{
		i++;
		ref = (ref)->next;
	}
	return (i);
}

t_node	*find_min_node(t_node *stack)
{
	long	min_num;
	t_node	*min_node;

	min_num = LONG_MAX;
	if (stack == NULL)
		return (NULL);
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

long	find_max_num(t_node **stack)
{
	long	max_num;
	t_node	*ref;

	ref = *stack;
	max_num = LONG_MIN;
	if (ref == NULL)
		return (-1);
	while (ref)
	{
		if (ref->data > max_num)
			max_num = (ref)->data;
		ref = ref->next;
	}
	return (max_num);
}
