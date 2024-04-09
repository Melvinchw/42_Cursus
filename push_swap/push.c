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

void	push(t_node **src, t_node **dst)
{
	t_node	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

int	count_stack(t_node **stack)
{
	int	i;

	i = 0;
	if (*stack == NULL)
		return (i);
	while (*stack)
	{
		i++;
		*stack = (*stack)->next;
	}
	return (i);
}
