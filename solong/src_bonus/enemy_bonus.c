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
	}
}

void	enemy_new_pos(t_enemy enemy)
{
	if (enemy.direction == MOVE_UP)
		enemy.y--;
	else if (enemy.direction == MOVE_DOWN)
		enemy.y++;
	else if (enemy.direction == MOVE_LEFT)
		enemy.x--;
	else if (enemy.direction == MOVE_RIGHT)
		enemy.x++;
}

void	enemy_change_direction(t_enemy enemy)
{
	if (enemy.direction < 3)
		enemy.direction++;
	else
		enemy.direction = 0;
}

void	move_enemy(t_window *window)
{
	static int	count;
	int			i;

	i = 0;
	count++;
	if (count < EN_MOVEMENT)
		return ;
	while (i < window->enemy_no)
	{
		if (enemy_move_valid(window))
		{
			img_put(window, window->map.floor_img.img_ptr,
				 window->enemy[i].y, window->enemy[i].x);
			enemy_new_pos(window->enemy[i]);
		}
		else
		{
			img_put(window, window->map.floor_img.img_ptr,
				 window->enemy[i].y, window->enemy[i].x);
			enemy_change_direction(window->enemy[i]);
		}
		display_enemy(window);
		i++;
	}
	count = 0;
}

int	enemy_move_valid(t_window *window)
{
	if (window->enemy->direction == MOVE_UP && !ft_strrchr("1CE", window->map_array[window->enemy->y - 1][window->enemy->x]))
		return (1);
	if (window->enemy->direction == MOVE_DOWN && !ft_strrchr("1CE", window->map_array[window->enemy->y + 1][window->enemy->x]))
		return (1);
	if (window->enemy->direction == MOVE_RIGHT && !ft_strrchr("1CE", window->map_array[window->enemy->y][window->enemy->x + 1]))
		return (1);
	if (window->enemy->direction == MOVE_LEFT && !ft_strrchr("1CE", window->map_array[window->enemy->y][window->enemy->x - 1]))
		return (1);
	return (0);
}
