/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//determine path from player's start position to exit
void	check_path(t_game *game, char **tmp_map, int x, int y)
{
	if (x < 0 || y > game->height || y < 0 || x > game->width || \
		tmp_map[y][x] == '1')
		return ;
	if (tmp_map[y][x] == 'E')
		game->map.path_exit = 1;
	if (tmp_map[y][x] == 'C')
		game->map.path_coins++;
	if (game->map.path_exit && game->map.path_coins != game->map.coins)
		return ;
	tmp_map[y][x] = '1';
	check_path(game, tmp_map, x + 1, y);
	check_path(game, tmp_map, x - 1, y);
	check_path(game, tmp_map, x, y + 1);
	check_path(game, tmp_map, x, y - 1);
}

//determine starting position of player
void	check_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			if (game->map_arr[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

//initialise the height and width of game
void	set_game_size(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
			x++;
		y++;
	}
	game->width = x;
	game->height = y;
}

//initialise struct variables of t_map within game
void	initialise_t_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->width = 0;
	game->height = 0;
	game->map_arr = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.up = 0;
	game->player.down = 0;
	game->player.left = 0;
	game->player.right = 0;
	game->player.move = 0;
	game->player.coins = 0;
	game->player.win = 0;
	game->map.path_exit = 0;
	game->map.path_coins = 0;
	game->map.coins = 0;
	game->map.start = 0;
	game->map.exit = 0;
}
