/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:31:59 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:31:59 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	correct_input(char *argv)
{
	int	i;

	i = 1;
	if (ft_strlen(argv) == 0 || ft_strlen(argv) > 11)
		return (false);
	if (*argv != '-' && *argv != '+')
	{
		if (!ft_isdigit(*argv))
			return (false);
	}
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	is_duplicate(t_node *stack_a, int argv)
{
	if (!stack_a)
		return (false);
	while (stack_a->next != NULL)
	{
		if (argv == stack_a->data)
			return (true);
		else
			stack_a = stack_a->next;
	}
	return (false);
}

long	convert_number(char *argv)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign *= -1;
		i++;
	}
	while (argv[i])
	{
		value = value * 10 + (argv[i] - 48);
		i++;
	}
	return (value * sign);
}

bool	in_order(t_node *stack_a)
{
	int	num;

	if (!stack_a)
		return (false);
	num = stack_a->data;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (num > stack_a->data)
			return (false);
		num = stack_a->data;
		stack_a = stack_a->next;
	}
	return (true);
}
