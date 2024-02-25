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

t_img	load_image(t_window *window, char *filepath)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(window->mlx_ptr,
			filepath, &img.x, &img.y);
	return (img);
}

void	initialize_structure(t_window *window)
{
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->map.coins = 0;
	window->map.exit = 0;
	window->map.player = 0;
	window->map.exit_check = 0;
	window->map.coins_check = 0;
	window->player.x = 0;
	window->player.y = 0;
	window->player.dir = MOVE_DOWN;
	window->player.animation_counter = 0;
	window->player.coins_collected = 0;
	window->player.move_no = 0;
	window->length = 0;
	window->height = 0;
	window->map_array = 0;
	window->enemy_no = 0;
}

void	asset_to_characters(t_window *window)
{
	window->map.exit_img = load_image(window, EXIT);
	window->map.wall_img = load_image(window, WALL);
	window->map.floor_img = load_image(window, FLOOR);
	window->map.coin_img[0] = load_image(window, COINS_1);
	window->map.coin_img[1] = load_image(window, COINS_2);
	window->map.coin_img[2] = load_image(window, COINS_3);
	window->map.coin_img[3] = load_image(window, COINS_4);
	window->map.coin_img[4] = load_image(window, COINS_5);
	window->map.coin_img[5] = load_image(window, COINS_6);
	window->map.player_1[MOVE_RIGHT] = load_image(window, TURN_RIGHT_1);
	window->map.player_1[MOVE_LEFT] = load_image(window, TURN_LEFT_1);
	window->map.player_1[MOVE_UP] = load_image(window, TURN_UP_1);
	window->map.player_1[MOVE_DOWN] = load_image(window, TURN_DOWN);
	window->map.player_2[MOVE_RIGHT] = load_image(window, TURN_RIGHT_2);
	window->map.player_2[MOVE_LEFT] = load_image(window, TURN_LEFT_2);
	window->map.player_2[MOVE_UP] = load_image(window, TURN_UP_2);
	window->map.player_2[MOVE_DOWN] = load_image(window, TURN_DOWN);
	window->map.en_img = load_image(window, EN);
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

void	initialize_enemy(t_window *window)
{
	int	y;
	int	x;
	int	i;

	i = 0;
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
				window->enemy[i].dir = MOVE_UP;
				i++;
			}
			x++;
		}
		y++;
	}
}
