/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_attributes_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:18:40 by mchua             #+#    #+#             */
/*   Updated: 2024/01/30 23:22:27 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	check_attributes(t_window *window, char *buffer)
{
	char	**tempbuf;

	initialize_map(window);
	rectangle_check(window, window->height);
	wall_check(window, window->length, window->height);
	token_check(window);
	player_pos(window);
	tempbuf = ft_split(buffer, '\n');
	path_check(window, tempbuf, window->player.x, window->player.y);
	free_array(tempbuf);
	if (window->map.exit_check == 0)
		handle_error(3, "No exit within map!", window);
}
