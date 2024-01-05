/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game, int x, int y)
{
	if (game->map_arr[y - 1][x] == '0')
	{
		game->player.y--;
		game->map_arr[y][x] = '0';
		game->map_arr[y - 1][x] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y - 1][x] == 'C')
	{
		game->player.coins++;
		game->map.coins--;
		game->player.y--;
		game->map_arr[y][x] = '0';
		game->map_arr[y - 1][x] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y - 1][x] == 'E')
	{
		if (game->map.coins == 0)
			exit_game(game);
	}
}

void	move_down(t_game *game, int x, int y)
{
	if (game->map_arr[y + 1][x] == '0')
	{
		game->player.y++;
		game->map_arr[y][x] = '0';
		game->map_arr[y + 1][x] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y + 1][x] == 'C')
	{
		game->player.coins++;
		game->map.coins--;
		game->player.y++;
		game->map_arr[y][x] = '0';
		game->map_arr[y + 1][x] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y + 1][x] == 'E')
	{
		if (game->map.coins == 0)
			exit_game(game);
	}
}

void	move_right(t_game *game, int x, int y)
{
	if (game->map_arr[y][x + 1] == '0')
	{
		game->player.x++;
		game->map_arr[y][x] = '0';
		game->map_arr[y][x + 1] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y][x + 1] == 'C')
	{
		game->player.coins++;
		game->map.coins--;
		game->player.x++;
		game->map_arr[y][x] = '0';
		game->map_arr[y][x + 1] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y][x + 1] == 'E')
	{
		if (game->map.coins == 0)
			exit_game(game);
	}
}

void	move_left(t_game *game, int x, int y)
{
	if (game->map_arr[y][x - 1] == '0')
	{
		game->player.x--;
		game->map_arr[y][x] = '0';
		game->map_arr[y][x - 1] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y][x - 1] == 'C')
	{
		game->player.coins++;
		game->map.coins--;
		game->player.x--;
		game->map_arr[y][x] = '0';
		game->map_arr[y][x - 1] = 'P';
		game->player.move++;
		ft_printf("move: %d\n", game->player.move);
	}
	else if (game->map_arr[y][x - 1] == 'E')
	{
		if (game->map.coins == 0)
			exit_game(game);
	}
}

//updates E, C and P position in map
int	key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (keycode == W_KEY && game->map_arr[y - 1][x] != '1')
		move_up(game, x, y);
	else if (keycode == S_KEY && game->map_arr[y + 1][x] != '1')
		move_down(game, x, y);
	else if (keycode == D_KEY && game->map_arr[y][x + 1] != '1')
		move_right(game, x, y);
	else if (keycode == A_KEY && game->map_arr[y][x - 1] != '1')
		move_left(game, x, y);
	else if (keycode == ESC)
		close_game(game);
	else
		ft_printf("Invalid move\n");
	render_map(game);
	return (0);
}
