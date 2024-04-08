/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:55:14 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:55:14 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2 || (argc < 2 && !*argv[1]))
		handle_error(1, "Incorrect inputs");
	else if (argc == 2)
	{
		argv = split_args(argv[1], ' ');
		if (!argv)
			handle_error(1, "Invalid Arguments\n");
	}
	stack_init(stack_a, argv + 1);
	check_null(stack_a);
	if (!in_order(stack_a))
		push_swap(stack_a, stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
