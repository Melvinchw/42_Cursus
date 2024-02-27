/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:00:02 by mchua             #+#    #+#             */
/*   Updated: 2024/01/25 17:00:02 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_up(t_window *window, int y, int x)
{
	if (window->map_array[y - 1][x] == '0'
		|| window->map_array[y - 1][x] == 'C')
	{
		window->map_array[y][x] = '0';
		if (window->map_array[y - 1][x] == 'C')
			window->player.coins_collected++;
		window->player.y--;
		if (window->map.player_img.img_ptr)
			mlx_destroy_image(window->mlx_ptr, window->map.player_img.img_ptr);
		window->map.player_img = load_image(window->mlx_ptr, TURN_UP);
		window->player.move_no++;
		ft_printf("Move count: %d\n", window->player.move_no);
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
		window->map_array[y][x] = '0';
		if (window->map_array[y + 1][x] == 'C')
			window->player.coins_collected++;
		window->player.y++;
		if (window->map.player_img.img_ptr)
			mlx_destroy_image(window->mlx_ptr, window->map.player_img.img_ptr);
		window->map.player_img = load_image(window->mlx_ptr, TURN_DOWN);
		window->player.move_no++;
		ft_printf("Move count: %d\n", window->player.move_no);
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
		window->map_array[y][x] = '0';
		if (window->map_array[y][x - 1] == 'C')
			window->player.coins_collected++;
		window->player.x--;
		if (window->map.player_img.img_ptr)
			mlx_destroy_image(window->mlx_ptr, window->map.player_img.img_ptr);
		window->map.player_img = load_image(window->mlx_ptr, TURN_LEFT);
		window->player.move_no++;
		ft_printf("Move count: %d\n", window->player.move_no);
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
		window->map_array[y][x] = '0';
		if (window->map_array[y][x + 1] == 'C')
			window->player.coins_collected++;
		window->player.x++;
		if (window->map.player_img.img_ptr)
			mlx_destroy_image(window->mlx_ptr, window->map.player_img.img_ptr);
		window->map.player_img = load_image(window->mlx_ptr, TURN_RIGHT);
		window->player.move_no++;
		ft_printf("Move count: %d\n", window->player.move_no);
	}
	else if (window->map_array[y][x + 1] == 'E')
		if (window->map.coins == window->player.coins_collected)
			handle_exit(1, window);
}

int	handle_event(int keysym, t_window *window)
{
	if (keysym == ESC)
	{
		ft_printf("Escape key pressed!\n");
		handle_exit(4, window);
	}
	if (keysym == KEY_W
		&& window->map_array[window->player.y - 1][window->player.x] != '1')
		move_up(window, window->player.y, window->player.x);
	else if (keysym == KEY_S
		&& window->map_array[window->player.y + 1][window->player.x] != '1')
		move_down(window, window->player.y, window->player.x);
	else if (keysym == KEY_A
		&& window->map_array[window->player.y][window->player.x - 1] != '1')
		move_left(window, window->player.y, window->player.x);
	else if (keysym == KEY_D
		&& window->map_array[window->player.y][window->player.x + 1] != '1')
		move_right(window, window->player.y, window->player.x);
	else
	{
		ft_printf("Invalid move! Try again.\n");
		ft_printf("directional Keys are:\nUp: W\nDown: S\n");
		ft_printf("Left: A\nRight: D\n");
	}
	map_renderer(window);
	return (0);
}
