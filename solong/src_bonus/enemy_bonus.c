/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:09:05 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:09:05 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	collision_check(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->enemy_no)
	{
		if (window->enemy[i].y == window->player.y 
			&& window->enemy[i].x == window->player.x)
			handle_exit(2, window);
		i++;
	}
}

void	enemy_new_pos(t_enemy *enemy)
{
	if (enemy->dir == MOVE_UP)
		enemy->y--;
	else if (enemy->dir == MOVE_DOWN)
		enemy->y++;
	else if (enemy->dir == MOVE_LEFT)
		enemy->x--;
	else if (enemy->dir == MOVE_RIGHT)
		enemy->x++;
}

void	enemy_change_direction(t_window *window, t_enemy *enemy)
{
	while (!enemy_move_valid(window, *enemy))
	{
		if (enemy->dir != 3)
			enemy->dir++;
		else
			enemy->dir = 0;
	}
	window->map_array[enemy->y][enemy->x] = '0';
	img_put(window, window->map.floor_img.img_ptr,
		enemy->y, enemy->x);
	enemy_new_pos(enemy);
}

void	move_enemy(t_window *window)
{
	static int	count;
	int			i;

	count++;
	if (count < EN_MOVEMENT)
		return ;
	i = 0;
	while (i < window->enemy_no)
	{
		if (enemy_move_valid(window, window->enemy[i]))
		{
			window->map_array[window->enemy[i].y][window->enemy[i].x] = '0';
			img_put(window, window->map.floor_img.img_ptr,
				window->enemy[i].y, window->enemy[i].x);
			enemy_new_pos(&window->enemy[i]);
		}
		else
			enemy_change_direction(window, &window->enemy[i]);
		display_enemy(window);
		i++;
	}
	count = 0;
}

int	enemy_move_valid(t_window *window, t_enemy enemy)
{
	if (enemy.dir == MOVE_UP 
		&& !ft_strrchr("1CE", window->map_array[enemy.y - 1][enemy.x]))
		return (1);
	if (enemy.dir == MOVE_DOWN 
		&& !ft_strrchr("1CE", window->map_array[enemy.y + 1][enemy.x]))
		return (1);
	if (enemy.dir == MOVE_RIGHT 
		&& !ft_strrchr("1CE", window->map_array[enemy.y][enemy.x + 1]))
		return (1);
	if (enemy.dir == MOVE_LEFT 
		&& !ft_strrchr("1CE", window->map_array[enemy.y][enemy.x - 1]))
		return (1);
	return (0);
}
