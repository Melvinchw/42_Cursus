/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:29 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:08:29 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	empty_map_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer [i + 1] == '\n')
		{
			free(buffer);
			handle_error(2, "Empty Line!", NULL);
		}
		i++;
	}
}

void	valid_map_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P' || buffer[i] == 'E' || buffer[i] == '1'
			|| buffer[i] == 'C' || buffer[i] == '0' || buffer[i] == 'B' 
			|| buffer[i] == '\n')
			i++;
		else
		{
			free(buffer);
			handle_error(2, "Invalid characters!", NULL);
		}
	}
}
