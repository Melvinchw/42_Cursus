/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:28:02 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:28:02 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = stack_tail(stack);
	head = (*stack)->next;
	tail->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tail;
	*stack = head;
	(*stack)->prev = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	r_both(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
