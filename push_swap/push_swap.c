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

void	print_stack(t_node *stack_a, t_node *original)
{
	ft_printf("Original Stack\n");
	while (original)
	{
		ft_printf("%d ", original->data);
		original = original->next;
	}
	ft_printf("\nSorted Stack\n");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->data);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*original;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc < 2 && !*argv[1]))
		handle_error(1, "Incorrect inputs", NULL);
	else if (argc == 2)
	{
		argv = split_args(argv[1], ' ');
		if (!argv)
			handle_error(1, "Invalid Arguments\n", NULL);
	}
	stack_init(&stack_a, argv + 1);
	original = stack_a;
	if (!in_order(stack_a))
		push_swap(&stack_a, &stack_b);
	print_stack(stack_a, original);
	free(stack_a);
	return (0);
}
