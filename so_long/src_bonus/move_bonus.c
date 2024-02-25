/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:20 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:08:20 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	move_up(t_window *window, int y, int x)
{
	if (window->map_array[y - 1][x] == '0' 
		|| window->map_array[y - 1][x] == 'C')
	{
		window->player.dir = MOVE_UP;
		if (window->map_array[y - 1][x] == 'C')
			window->player.coins_collected++;
		update_pos(window, window->player.dir, y, x);
	}
	else if (window->map_array[y - 1][x] == 'E')
		if (window->map.coins == window->player.coins_collected)
			handle_exit(1, window);
}

void	move_down(t_window *window, int y, int x)
{
	if (window->map_array[y + 1][x] == '0' 
		|| window->map_array[y + 1][x] == 'C')
	{
		window->player.dir = MOVE_DOWN;
		if (window->map_array[y + 1][x] == 'C')
			window->player.coins_collected++;
		update_pos(window, window->player.dir, y, x);
	}
	else if (window->map_array[y + 1][x] == 'E')
		if (window->map.coins == window->player.coins_collected)
			handle_exit(1, window);
}

void	move_left(t_window *window, int y, int x)
{
	if (window->map_array[y][x - 1] == '0' 
		|| window->map_array[y][x - 1] == 'C')
	{
		window->player.dir = MOVE_LEFT;
		if (window->map_array[y][x - 1] == 'C')
			window->player.coins_collected++;
		update_pos(window, window->player.dir, y, x);
	}
	else if (window->map_array[y][x - 1] == 'E')
		if (window->map.coins == window->player.coins_collected)
			handle_exit(1, window);
}

void	move_right(t_window *window, int y, int x)
{
	if (window->map_array[y][x + 1] == '0' 
		|| window->map_array[y][x + 1] == 'C')
	{
		window->player.dir = MOVE_RIGHT;
		if (window->map_array[y][x + 1] == 'C')
			window->player.coins_collected++;
		update_pos(window, window->player.dir, y, x);
	}
	else if (window->map_array[y][x + 1] == 'E')
		if (window->map.coins == window->player.coins_collected)
			handle_exit(1, window);
}

void	update_pos(t_window *window, int dir, int y, int x)
{
	window->map_array[y][x] = '0';
	if (dir == MOVE_UP)
		window->player.y--;
	else if (dir == MOVE_DOWN)
		window->player.y++;
	else if (dir == MOVE_LEFT)
		window->player.x--;
	else if (dir == MOVE_RIGHT)
		window->player.x++;
	window->map_array[window->player.y][window->player.x] = 'P';
	window->player.move_no++;
	ft_printf("Move count: %d\n", window->player.move_no);
}
