/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:36 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:08:36 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	handle_event(int keysym, t_window *window)
{
	if (keysym == ESC)
	{
		ft_printf("Escape key pressed!\n");
		handle_exit(3, window);
	}
	if (keysym == KEY_W && 
		window->map_array[window->player.y - 1][window->player.x] != '1')
		move_up(window, window->player.y, window->player.x);
	else if (keysym == KEY_S && 
		window->map_array[window->player.y + 1][window->player.x] != '1')
		move_down(window, window->player.y, window->player.x);
	else if (keysym == KEY_A && 
		window->map_array[window->player.y][window->player.x - 1] != '1')
		move_left(window, window->player.y, window->player.x);
	else if (keysym == KEY_D && 
		window->map_array[window->player.y][window->player.x + 1] != '1')
		move_right(window, window->player.y, window->player.x);
	else
	{
		ft_printf("Invalid move! Try again.\n");
		ft_printf("directional Keys are:\nUp: W\nDown: S\nLeft: A\nRight: D\n");
	}
	display_map(window);
	return (0);
}

int	update_enemy(t_window *window)
{
	collision_check(window);
	move_enemy(window);
	display_coins(window, true);
	display_moves(window);
	return (0);
}

void	init_game(char *buffer)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		ft_printf("Allocation error!\n");
	empty_map_check(buffer);
	valid_map_check(buffer);
	initialize_structure(window);
	window->map_array = ft_split(buffer, '\n');
	check_attributes(window, buffer);
	free(buffer);
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->length * SPRITE,
			window->height * SPRITE, "SOOO_LOONG_BONUS! :)");
	asset_to_characters(window);
	if (window->enemy_no > 0)
	{
		initialize_enemy(window);
		display_enemy(window);
	}
	display_map(window);
	mlx_key_hook(window->win_ptr, handle_event, window);
	mlx_loop_hook(window->mlx_ptr, update_enemy, window);
	mlx_loop(window->mlx_ptr);
}
