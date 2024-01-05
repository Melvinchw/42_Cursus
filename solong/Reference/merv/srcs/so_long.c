/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:20:24 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:20:41 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_game_conditions(t_game *game, char *buf)
{
	char	**tmp_map;

	set_game_size(game);
	check_map_conditions(game->map_arr, game);
	check_rectangular(game->map_arr, game->width, game->height);
	check_wall(game->map_arr, game->width, game->height);
	check_player_position(game);
	tmp_map = ft_split(buf, '\n');
	check_path(game, tmp_map, game->player.x, game->player.y);
	free_map(tmp_map);
	if (game->map.path_exit == 0)
	{
		free_map(game->map_arr);
		ft_printf("Error: No valid path\n");
		exit (0);
	}
}

void	load_game(char *buf)
{
	t_game	*game;

	check_empty_map(buf);
	check_valid_map(buf);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit (0);
	initialise_t_game(game);
	game->map_arr = ft_split(buf, '\n');
	check_game_conditions(game, buf);
	free(buf);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * SPRITE_SIZE, \
		game->height * SPRITE_SIZE, "so_long");
	initialise_assets(game);
	render_map(game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_hook(game->window, ON_DESTROY, 0, close_game, game);
	mlx_loop(game->mlx);
}

//passes in a valid ber file
int	main(int argc, char **argv)
{
	int		fd;
	char	*buf;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Only 1 map\n", 2);
		exit (0);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_putstr_fd("Error: Not ber file\n", 2);
		exit (0);
	}
	fd = open(argv[1], O_RDONLY);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (-1);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
	{
		ft_printf("Error: Empty file\n");
		free(buf);
		return (-1);
	}
	load_game(buf);
}
