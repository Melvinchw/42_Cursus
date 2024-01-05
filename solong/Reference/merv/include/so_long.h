/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:14:44 by mertan            #+#    #+#             */
/*   Updated: 2023/12/28 14:16:59 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>

// Keys definition
# include "../minilibx-linux/mlx.h"
# define W_KEY 		119
# define S_KEY 		115
# define A_KEY 		97
# define D_KEY 		100
# define ESC 		65307
# define ON_DESTROY 17

// Define path for assets
# define WALL			"./assets/wall.xpm"
# define FLOOR			"./assets/floor.xpm"
# define PLAYER_LEFT	"./assets/player_left.xpm"
# define PLAYER_RIGHT	"./assets/player_right.xpm"
# define PLAYER_UP		"./assets/player_up.xpm"
# define PLAYER_DOWN	"./assets/player_down.xpm"
# define EXIT			"./assets/exit.xpm"
# define COIN			"./assets/coin.xpm"

# define SPRITE_SIZE 32
# define BUFFER_SIZE 1000

//struct for image
typedef struct s_img
{
	void	*ptr;
	int		x;
	int		y;
}	t_img;

//struct for player
typedef struct s_player
{
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
	int		move;
	int		coins;
	bool	win;
}	t_player;

//struct for map
typedef struct s_map
{
	int		exit;
	int		coins;
	int		start;
	int		path_exit;
	int		path_coins;
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_player;
	t_img	img_coin;
	t_img	img_exit;
}	t_map;

//struct for game attributes
typedef struct s_game 
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	char		**map_arr;
	t_player	player;
	t_map		map;
}	t_game;

//exit.c
void	exit_game(t_game *game);
int		close_game(t_game *game);
void	free_map(char **s);

//move.c
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
int		key_hook(int keycode, t_game *game);

//render,c
void	img_to_window(t_game *game, t_img *ptr, int y, int x);
void	render_map(t_game *game);
t_img	load_image(void *mlx, char *path);
void	initialise_assets(t_game *game);

//initialise.c
void	check_path(t_game *game, char **tmp_map, int x, int y);
void	check_player_position(t_game *game);
void	set_game_size(t_game *game);
void	initialise_t_game(t_game *game);

//check.c
void	check_wall(char **map_arr, int width, int height);
void	check_rectangular(char **map_arr, int width, int height);
void	check_map_conditions(char **map_arr, t_game *game);
void	check_valid_map(char *buf);
void	check_empty_map(char *buf);

//so_long.c
void	check_game_conditions(t_game *game, char *buf);
void	load_game(char *buf);
int		main(int argc, char **argv);

#endif
