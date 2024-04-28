/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:58:18 by mchua             #+#    #+#             */
/*   Updated: 2024/04/28 08:41:59 by mchua            ###   ########.fr       */
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
	write (2, str, 6);
	if (stack)
		free_stack(stack);
	if (argv != NULL && arg_flag == 2)
		free_array(argv);
	exit(EXIT_FAILURE);
}

void	free_stack(t_node **stack)
{
	t_node	*ref;

	ref = *stack;
	while (ref)
	{
		*stack = ((*stack)->next);
		free (ref);
		ref = *stack;
	}
}
