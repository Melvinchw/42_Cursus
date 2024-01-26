/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:00:39 by mchua             #+#    #+#             */
/*   Updated: 2024/01/25 17:00:39 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*buffer;

	if (argc != 2)
		handle_error(1, "Incorrect number of inputs!", NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		handle_error(1, "Wrong file format!\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error(2, "Error opening file!", NULL);
	buffer = ft_calloc(BUFFER + 1, sizeof(char));
	if (!buffer)
		return (-1);
	if (read(fd, buffer, BUFFER) <= 0)
	{
		free(buffer);
		handle_error(2, "Empty map file!", NULL);
		return (-1);
	}
	init_game(buffer);
	return (0);
}
