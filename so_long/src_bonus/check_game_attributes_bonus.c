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
	if (token_check(window) == 1 || \
		rectangle_check(window, window->height) == 2 || \
		wall_check(window, window->length, window->height) == 3)
	{
		free(buffer);
		if (1)
			handle_error(3, "Wrong token count!", window);
		else if (2)
			handle_error(3, "Map not rectangular!", window);
		else
			handle_error(3, "Map not fully surrounded by walls!", window);
	}
	player_pos(window);
	tempbuf = ft_split(buffer, '\n');
	path_check(window, tempbuf, window->player.x, window->player.y);
	free_array(tempbuf);
	if (window->map.exit_check == 0)
	{
		free(buffer);
		handle_error(3, "No exit within map!", window);
	}
}
