/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:21:46 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:21:46 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate(t_node *stack)
{
	t_node	*tail;
	t_node	*head;

	tail = stack_tail(stack);
	if (stack == NULL || stack->next == NULL)
		return ;
	head = tail;
	head->next = stack->next;
	stack = head;
	tail->prev = tail->prev->prev;
	tail = tail->prev;
	head->prev = NULL;
	tail->next = NULL;
}

void	rra(t_node *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rr_both(t_node *stack_a, t_node *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
