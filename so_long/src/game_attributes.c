/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_attributes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:59:28 by mchua             #+#    #+#             */
/*   Updated: 2024/01/25 16:59:28 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	rectangle_check(t_window *window, int height)
{
	int	reference_width;
	int	y;

	y = 0;
	reference_width = ft_strlen(window->map_array[y]);
	while (y < height - 1)
	{
		if (ft_strlen(window->map_array[y]) != reference_width)
			return (2);
		y++;
	}
	return (0);
}

int	wall_check(t_window *window, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < width)
	{
		if (window->map_array[0][x] != '1' ||
				window->map_array[height - 1][x] != '1')
			return (3);
		x++;
	}
	while (y < height)
	{
		if (window->map_array[y][0] != '1' ||
				window->map_array[y][width - 1] != '1')
			return (3);
		y++;
	}
	return (0);
}

int	token_check(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			if (window->map_array[y][x] == 'P')
				window->map.player++;
			if (window->map_array[y][x] == 'E')
				window->map.exit++;
			if (window->map_array[y][x] == 'C')
				window->map.coins++;
			x++;
		}
		y++;
	}
	if (window->map.player != 1 || window->map.exit != 1 || !window->map.coins)
		return (1);
	return (0);
}

void	path_check(t_window *window, char **tempbuf, int x, int y)
{
	if ((tempbuf[y][x]) == '1')
		return ;
	if (tempbuf[y][x] == 'E')
	{
		window->map.exit_check = 2;
		return ;
	}
	if (tempbuf[y][x] == 'C')
		window->map.coins_check++;
	if (window->map.exit_check == 2
		&& window->map.coins != window->map.coins_check)
		return ;
	tempbuf[y][x] = '1';
	path_check(window, tempbuf, x, y - 1);
	path_check(window, tempbuf, x, y + 1);
	path_check(window, tempbuf, x + 1, y);
	path_check(window, tempbuf, x - 1, y);
}

void	check_attributes(t_window *window, char *buffer)
{
	char	**tempbuf;

	initialize_map(window);
	rectangle_check(window, window->height);
	wall_check(window, window->length, window->height);
	if (token_check(window) == 1 || rectangle_check(window, window->height) == 2
		|| wall_check(window, window->length, window->height) == 3)
	{
		free(buffer);
		if (1)
			handle_error(3, "Wrong Token Count!", window);
		else if (2)
			handle_error(3, "Map not rectangular!", window);
		else
			handle_error(3, "Map not surrounded by walls!", window);
	}
	player_pos(window);
	tempbuf = ft_split(buffer, '\n');
	path_check(window, tempbuf, window->player.x, window->player.y);
	free_array(tempbuf);
	if (window->map.exit_check == 0)
	{
		free(buffer);
		handle_error(3, "No exit found!", window);
	}
}
