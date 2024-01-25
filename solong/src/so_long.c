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
		ft_printf("Incorrect number of input");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 4))
		ft_printf("Wrong file format\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_printf("Error opening file\n");
	buffer = ft_calloc(BUFFER + 1, sizeof(char));
	if (!buffer)
		return (-1);
	if (read(fd, buffer, BUFFER) <= 0)
	{
		free(buffer);
		ft_printf("Empty map file!\n");
		return (-1);
	}
	init_game(buffer);
	return (0);
}
