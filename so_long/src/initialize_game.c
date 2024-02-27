/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:59:49 by mchua             #+#    #+#             */
/*   Updated: 2024/01/25 16:59:49 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_game(char *buffer)
{
	t_window	*window;

	window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!window)
		ft_printf("Allocation error\n");
	empty_map_check(buffer);
	valid_map_check(buffer);
	initialize_structure(window);
	window->map_array = ft_split(buffer, '\n');
	check_attributes(window, buffer);
	free(buffer);
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			window->length * SPRITE, window->height * SPRITE, "SOOO_LOONG!");
	asset_to_characters(window);
	map_renderer(window);
	mlx_key_hook(window->win_ptr, handle_event, window);
	mlx_hook(window->win_ptr, 17, 0L, exit_game, window);
	mlx_loop(window->mlx_ptr);
}
