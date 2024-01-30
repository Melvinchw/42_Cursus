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

t_img	load_image(t_window *window, char *filepath)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, filepath, &img.x, &img.y);
	return (img);
}

void	img_put(t_window *window, t_img *img_ptr, int y, int x)
{
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, 
		img_ptr, (x * SPRITE), (y * SPRITE));
}

void	display_coins(t_window *window)
{
	static int	i;
	static int	count;
	int			y;
	int			x;

	count++;
	y = 0;
	if (count < ANIMATION_COUNTER)
		return ;
	while (window->map_array[y])
	{
		x = 0;
		while (window->map_array[y][x])
		{
			if (window->map_array[y][x] == 'C')
				img_put(window, window->map.coin_img[i].img_ptr,
					 window->map.coin_img[i].y, window->map.coin_img[i].x);
			x++;
		}
		y++;
	}
	if (i++ == 5)
		i = 0;
	count = 0;
}

void	display_player(t_window *window)
{
	if (window->player.animation_counter == 1)
	{
		img_put(window, window->map.player_1[window->player.direction].img_ptr, window->player.y, window->player.x);
		window->player.animation_counter = 0;
	}
	if (window->player.animation_counter == 1)
	{
		img_put(window, window->map.player_2[window->player.direction].img_ptr, window->player.y, window->player.x);
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
//			else if (window->map_array[y][x] == 'C')
//				img_put(window, window->map.coin_img.img_ptr, y, x);
			else if (window->map_array[y][x] == '0')
				img_put(window, window->map.floor_img.img_ptr, y, x);
			else if (window->map_array[y][x] == 'E')
				img_put(window, window->map.exit_img.img_ptr, y, x);
		}
	}
	display_coins(window);
	display_player(window);
	display_enemy(window);
}

void	display_enemy(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->enemy_no)
	{
//		if (window->enemy[i].dir == MOVE_UP)
		img_put(window, window->map.en_img.img_ptr, 
			window->enemy[i].y, window->enemy[i].x);
/*		else if (window->enemy[i].dir == MOVE_DOWN)
			img_put(window, window->map.en_down_img.img_ptr, 
				window->enemy.y, window->enemy.x);
		else if (window->enemy[i].dir == MOVE_LEFT)
			img_put(window, window->map.en_left_img.img_ptr, 
				window->enemy.y, window->enemy.x);
		else if (window->enemy[i].dir == MOVE_RIGHT)
			img_put(window, window->map.en_right_img.img_ptr, 
				window->enemy.y, window->enemy.x);*/
		i++;
	}
}

void	display_moves(t_window *window)
{
	char	*move_no;

	move_no = ft_itoa(window->player.move_no);
	mlx_string_put(window->mlx_ptr, window->win_ptr, 16, 16, WHITE, "Moves: ");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 55, 16, WHITE, move_no);
	free(move_no);
}
