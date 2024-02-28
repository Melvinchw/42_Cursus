/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:21:39 by mchua             #+#    #+#             */
/*   Updated: 2024/02/28 23:21:44 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	error(void)
{
	perror("Error executing,goodbye bitch\n Error: ");
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
