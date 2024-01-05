/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_game *game)
{
	ft_printf("YOU WIN!\n");
	mlx_destroy_image(game->mlx, game->map.img_player.ptr);
	mlx_destroy_image(game->mlx, game->map.img_wall.ptr);
	mlx_destroy_image(game->mlx, game->map.img_floor.ptr);
	mlx_destroy_image(game->mlx, game->map.img_coin.ptr);
	mlx_destroy_image(game->mlx, game->map.img_exit.ptr);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(game->map_arr);
	free(game->mlx);
	free(game);
	exit (0);
}

int	close_game(t_game *game)
{
	ft_printf("Exit game\n");
	mlx_destroy_image(game->mlx, game->map.img_player.ptr);
	mlx_destroy_image(game->mlx, game->map.img_wall.ptr);
	mlx_destroy_image(game->mlx, game->map.img_floor.ptr);
	mlx_destroy_image(game->mlx, game->map.img_coin.ptr);
	mlx_destroy_image(game->mlx, game->map.img_exit.ptr);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(game->map_arr);
	free(game->mlx);
	free(game);
	exit (0);
}

void	free_map(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
