/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:58:18 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:59:28 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	handle_error(int i, char *str, char **argv)
{
	ft_printf("%s", str);
	if (i == 2)
		free_array(argv);
	exit (1);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv);
}

void	free_stack(t_node *stack)
{
	t_node	*ref;

	ref = stack;
	while (ref)
	{
		ref = stack->next;
		free (stack);
	}
	free (stack);
	exit (1);
}
