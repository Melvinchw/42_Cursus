/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:13 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:08:13 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	display_coins(t_window *window, bool start)
{
	static int	i;
	static int	count;
	int			y;
	int			x;

	count++;
	if (count < ANIMATION_COUNTER && start == true)
		return ;
	y = 0;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			if (window->map_array[y][x] == 'C')
				if (i >= 0 && i <= 5)
					img_put(window, window->map.coin_img[i].img_ptr, y, x);
			x++;
		}
		y++;
	}
	if (i++ == 5)
		i = 0;
	count = 0;
}

void	display_player(t_window *window, t_player player)
{
	if (window->player.animation_counter == 1)
	{
		img_put(window, window->map.player_1[player.dir].img_ptr,
			player.y, player.x);
		window->player.animation_counter = 0;
	}
	else
	{
		img_put(window, window->map.player_2[window->player.dir].img_ptr,
			player.y, player.x);
		window->player.animation_counter = 1;
	}
}

void	display_map(t_window *window)
{
	int	y;
	int	x;

	y = 0;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			if (window->map_array[y][x] == '1')
				img_put(window, window->map.wall_img.img_ptr, y, x);
			else if (window->map_array[y][x] == '0')
				img_put(window, window->map.floor_img.img_ptr, y, x);
			else if (window->map_array[y][x] == 'E')
				img_put(window, window->map.exit_img.img_ptr, y, x);
			x++;
		}
		y++;
	}
	display_player(window, window->player);
	display_enemy(window);
}

void	display_enemy(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->enemy_no)
	{
		img_put(window, window->map.en_img.img_ptr, 
			window->enemy[i].y, window->enemy[i].x);
		i++;
	}
}

void	display_moves(t_window *window)
{
	char	*move_no;

	move_no = ft_itoa(window->player.move_no);
	mlx_string_put(window->mlx_ptr, window->win_ptr, 38, 40, WHITE, "Moves: ");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 77, 40, WHITE, move_no);
	free(move_no);
}
