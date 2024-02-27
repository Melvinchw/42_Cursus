/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_attributes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:09:17 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:09:17 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	rectangle_check(t_window *window, int height)
{
	int	reference_width;
	int	y;

	y = 0;
	reference_width = ft_strlen(window->map_array[y]);
	while (y < height)
	{
		if (ft_strlen(window->map_array[y]) != reference_width \
			|| reference_width < height)
			return (2);
		y++;
	}
	return (0);
}

int	wall_check(t_window *window, int length, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < length)
	{
		if (window->map_array[0][x] != '1' \
			|| window->map_array[height - 1][x] != '1')
			return (3);
		x++;
	}
	while (y < height)
	{
		if (window->map_array[y][0] != '1' \
			|| window->map_array[y][length - 1] != '1')
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
			if (window->map_array[y][x] == 'B')
				window->enemy_no++;
			x++;
		}
		y++;
	}
	if (window->map.player != 1 \
		|| window->map.exit != 1 || window->map.coins < 1)
		return (1);
	return (0);
}

void	player_pos(t_window *window)
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
			{
				window->player.x = x;
				window->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
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
	if (window->map.exit_check == 2 \
		&& window->map.coins != window->map.coins_check)
		return ;
	tempbuf[y][x] = '1';
	path_check(window, tempbuf, x, y - 1);
	path_check(window, tempbuf, x, y + 1);
	path_check(window, tempbuf, x + 1, y);
	path_check(window, tempbuf, x - 1, y);
}
