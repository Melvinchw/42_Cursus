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

void	rectangle_check(t_window *window, int height)
{
	int	reference_width;
	int	y;

	y = 0;
	reference_width = ft_strlen(window->map_array[y]);
	while (y < height - 1)
	{
		if (ft_strlen(window->map_array[y]) != reference_width)
			handle_error(3, "Map not rectangular!", window);
		y++;
	}
}

void	wall_check(t_window *window, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < width)
	{
		if (window->map_array[0][x] != '1' ||
				window->map_array[height - 1][x] != '1')
			handle_error(3, "Map not surrounded by walls!", window);
		x++;
	}
	while (y < height)
	{
		if (window->map_array[y][0] != '1' ||
				window->map_array[y][width - 1] != '1')
			handle_error(3, "Map not surrounded by walls!", window);
		y++;
	}
}

void	token_check(t_window *window)
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
		handle_error(3, "Wrong Token Count!", window);
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
	/*if (window->map.exit_check == 0)
	{
		free (tempbuf);
		handle_error(3, "No Path Found!", window);
	}*/
}
//check_game_attributes
void	check_attributes(t_window *window, char *buffer)
{
	char	**tempbuf;

	initialize_map(window);
	rectangle_check(window, window->height);
	wall_check(window, window->length, window->height);
	token_check(window);
	player_pos(window);
	tempbuf = ft_split(buffer, '\n');
	path_check(window, tempbuf, window->player.x, window->player.y);
	free_array(tempbuf);
	if (window->map.exit == 0)
		handle_error(3, "No exit found!", window);
}
