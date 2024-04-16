/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:58:18 by mchua             #+#    #+#             */
/*   Updated: 2024/04/16 14:56:20 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

void	handle_error(t_node **stack, char *str, char **argv, int arg_flag)
{
	ft_printf("%s", str);
	if (stack)
		free_stack(stack);
	if (argv != NULL && arg_flag == 2)
		free_array(argv);
	exit(1);
}

void	free_stack(t_node **stack)
{
	t_node *ref;

	ref = *stack;
	while (ref)
	{
		*stack = ((*stack)->next);
		free (ref);
		ref = *stack;
	}
}
