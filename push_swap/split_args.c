/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <mchua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:46:30 by mchua             #+#    #+#             */
/*   Updated: 2024/04/08 20:46:30 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_null(void *ptr)
{
	if (ptr == NULL)
		handle_error(2, "Memory allocation error");
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
		if (*str == sep)
			flag = false;
		else if (!flag)
		{
			i++;
			flag = true;
		}
		str++;
	}
	if (!i)
		handle_error(1, "Invalid word count");
	return (i);
}

char	*next_word(char *str, char sep)
{
	char		*word;
	static int	counter;
	int			i;

	counter = 0;
	i = 0;
	while (str[counter] == sep)
		counter++;
	while (str[counter] != sep && str[counter + i] != '\0')
		i++;
	word = malloc((i * sizeof(char) + 1));
	check_null(word);
	i = 0;
	while ((str[counter] != '\0') && (str[counter] != sep))
		word[i++] = str[counter++];
	word[i] = '\0';
	return (word);
}

char	**split_args(char *str, char sep)
{
	int		i;
	int		count;
	char	**args;

	count = count_words(str, sep);
	args = malloc(count * sizeof(char));
	check_null(args);
	args[0] = '\0';
	i = 1;
	while (--count > 0)
	{
		args[i] = next_word(str, sep);
		i++;
	}
	args[i] = '\0';
	return (args);
}
