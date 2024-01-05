/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//put image to window, adjusted for each sprite size
void	img_to_window(t_game *game, t_img *ptr, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->window, ptr, 
		(x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

//render all t-img to window
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			if (game->map_arr[y][x] == '1')
				img_to_window(game, game->map.img_wall.ptr, y, x);
			else if (game->map_arr[y][x] == 'E')
				img_to_window(game, game->map.img_exit.ptr, y, x);
			else if (game->map_arr[y][x] == 'C')
				img_to_window(game, game->map.img_coin.ptr, y, x);
			else if (game->map_arr[y][x] == 'P')
				img_to_window(game, game->map.img_player.ptr, y, x);
			else
				img_to_window(game, game->map.img_floor.ptr, y, x);
			x++;
		}
		y++;
	}
	return ;
}

//initialise t_img from xpm to image
t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

//load all t_img within t_map
void	initialise_assets(t_game *game)
{
	game->map.img_wall = load_image(game->mlx, WALL);
	game->map.img_floor = load_image(game->mlx, FLOOR);
	game->map.img_player = load_image(game->mlx, PLAYER_RIGHT);
	game->map.img_coin = load_image(game->mlx, COIN);
	game->map.img_exit = load_image(game->mlx, EXIT);
	return ;
}
