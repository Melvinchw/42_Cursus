/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:37:17 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:37:17 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_null(void *ptr)
{
	if (ptr == NULL)
		handle_error(2, "Memory allocation error", NULL);
	else
		return ;
}

int	count_words(char *str, char sep)
{
	int		i;
	bool	flag;

	flag = true;
	i = 0;
	while (*str)
	{
		flag = false;
		while (*str == sep && str)
			str++;
		while (*str != sep && *str)
		{
			if (!flag)
			{
				i++;
				flag = true;
			}
			str++;
		}
	}
	if (!i)
		handle_error(1, "Invalid word count", NULL);
	return (i);
}

char	*next_word(char *str, char sep)
{
	char		*word;
	static int	counter = 0;
	int			i;

	i = 0;
		while (str[counter] == sep)
			counter++;
		while (str[counter + i] != sep && str[counter + i] != '\0')
			i++;
	word = ft_calloc(i + 1, sizeof(char));
	check_null(word);
	i = 0;
	while ((str[counter] != '\0') && (str[counter] != sep))
	{
		word[i] = str[counter];
		counter++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_args(char *str, char sep)
{
	int		i;
	int		count;
	char	**args;

	count = count_words(str, sep);
	args = malloc((count +1) * sizeof(char *));
	check_null(args);
	args[0] = '\0';
	i = 1;
	while (count > 0)
	{
		args[i] = next_word(str, sep);
		i++;
		count--;
	}
	args[i] = '\0';
	return (args);
}
