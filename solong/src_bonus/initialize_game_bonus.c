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
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			window->length * SPRITE, window->height * SPRITE, "SOOO_LOONG_BONUS! :)");
	asset_to_characters(window);
	if (window->enemy_no > 0)
	{
		initialize_enemy(window);
		display_enemy(window);
	}
	display_map(window);
	mlx_key_hook(window->win_ptr, handle_event, window);
	mlx_loop_hook(window->win_ptr, update_enemy, window);
	mlx_loop(window->mlx_ptr);
}
