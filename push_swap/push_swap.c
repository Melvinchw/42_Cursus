/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:33:38 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:33:38 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc < 2 && !*argv[1]))
		return (0);
	else if (argc == 2)
	{
		argv = split_args(argv[1], ' ');
		if (!argv)
			return (0);
	}
	stack_init(&stack_a, argv + 1, argc);
	if (!in_order(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
