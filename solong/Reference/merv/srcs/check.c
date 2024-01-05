/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_wall(char **map_arr, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < width - 1)
	{
		if (map_arr[0][x] != '1' || map_arr[height - 1][x] != '1')
		{
			free_map(map_arr);
			ft_printf("Error: Map not surrounded by wall\n");
			exit (0);
		}
		x++;
	}
	while (y < height - 1)
	{
		if (map_arr[y][0] != '1' || map_arr[y][width - 1] != '1')
		{
			free_map(map_arr);
			ft_printf("Error: Map not surrounded by wall\n");
			exit (0);
		}
		y++;
	}
}

//ensure all widths of each height are equal
void	check_rectangular(char **map_arr, int width, int height)
{
	int	i;

	i = 0;
	while (i < height - 1)
	{
		if (ft_strlen(map_arr[i]) != (size_t)width)
		{
			free_map(map_arr);
			ft_printf("Error: Map not rectangular\n");
			exit (0);
		}
		i++;
	}
}

// Checks if map has at least 1 exit, 1 collectible and 1 start position
void	check_map_conditions(char **map_arr, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (map_arr[y][x] == 'E')
				game->map.exit++;
			if (map_arr[y][x] == 'C')
				game->map.coins++;
			if (map_arr[y][x] == 'P')
				game->map.start++;
			x++;
		}
		y++;
	}
	if (!game->map.exit || !game->map.coins || game->map.start != 1)
	{
		free_map(map_arr);
		ft_printf("Error: Map dont have required E, C or P\n");
		exit (0);
	}
}

//check file for invalid characters
void	check_valid_map(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '0' && buf[i] != '1' && buf[i] != 'C'
			&& buf[i] != 'E' && buf[i] != 'P' && buf[i] != '\n')
		{
			free(buf);
			ft_printf("Error: Map has invalid characters\n");
			exit (0);
		}
		i++;
	}
}

//check for empty line
void	check_empty_map(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			free(buf);
			ft_printf("Error: Empty line\n");
			exit (0);
		}
		i++;
	}
}
