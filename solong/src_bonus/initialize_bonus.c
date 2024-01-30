/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:52 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:08:52 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void    initialize_structure(t_window *window)
{
	window->map.coins = 0;
	window->map.exit = 0;
	window->map.player = 0;
	window->map.exit_check = 0;
	window->map.coins_check = 0;
	window->player.x = 0;
	window->player.y = 0;
	window->player.direction = 0;
	window->player.animation_counter = 0;
	window->player.coins_collected = 0;
	window->player.move_no = 0;
	window->length = 0;
	window->height = 0;
	window->map_array = 0;
	window->enemy_no = 0;
	window->enemy[0].y = 0;
	window->enemy[0].x = 0;
	window->enemy[0].direction = 0;
}

void	asset_to_characters(t_window *window)
{
	window->map.coin_img[0] = load_image(window->mlx_ptr, COINS_1);
	window->map.coin_img[1] = load_image(window->mlx_ptr, COINS_2);
	window->map.coin_img[2] = load_image(window->mlx_ptr, COINS_3);
	window->map.coin_img[3] = load_image(window->mlx_ptr, COINS_4);
	window->map.coin_img[4] = load_image(window->mlx_ptr, COINS_5);
	window->map.coin_img[5] = load_image(window->mlx_ptr, COINS_6);
	window->map.exit_img = load_image(window->mlx_ptr, EXIT);
	window->map.wall_img = load_image(window->mlx_ptr, FLOOR);
	window->map.floor_img = load_image(window->mlx_ptr, WALL);
	window->map.player_1[MOVE_RIGHT] = load_image(window->mlx_ptr, TURN_RIGHT_1);
	window->map.player_1[MOVE_LEFT] = load_image(window->mlx_ptr, TURN_LEFT_1);
	window->map.player_1[MOVE_UP] = load_image(window->mlx_ptr, TURN_UP_1);
	window->map.player_1[MOVE_DOWN] = load_image(window->mlx_ptr, TURN_DOWN);
	window->map.player_2[MOVE_RIGHT] = load_image(window->mlx_ptr, TURN_RIGHT_2);
	window->map.player_2[MOVE_LEFT] = load_image(window->mlx_ptr, TURN_LEFT_2);
	window->map.player_2[MOVE_UP] = load_image(window->mlx_ptr, TURN_UP_2);
	window->map.en_img = load_image(window->mlx_ptr, EN);
}

void	initialize_map(t_window *window)
{
	int	y;
	int	x;

	y = 0;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			window->length++;
			x++;
		}
		window->height++;
		y++;
	}
	window->length /= window->height;
}

int	update_enemy(t_window *window)
{
	move_enemy(window);
	collision_check(window);
	display_moves(window);
	return (0);
}

void	initialize_enemy(t_window *window)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			if (window->map_array[y][x] == 'B')
			{
				window->enemy[i].y = y;
				window->enemy[i].x = x;
				window->enemy[i].direction = MOVE_UP;
				i++;
			}
			x++;
		}
		y++;
	}
}
