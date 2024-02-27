/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:52:33 by mchua             #+#    #+#             */
/*   Updated: 2024/02/19 21:53:21 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

//library inclusion
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

//variables declaration
//=====================
//Keys event handler
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307

//Process event handler
# define DESTROYWINDOW 17

//Asset filepath
# define WALL "./textures/bonus/wall.xpm"
# define FLOOR "./textures/bonus/floor.xpm"
# define TURN_RIGHT "./textures/bonus/turn_right_1.xpm"
# define TURN_LEFT "./textures/bonus/turn_left_1.xpm"
# define TURN_UP "./textures/bonus/turn_up_1.xpm"
# define TURN_DOWN "./textures/bonus/turn_down_1.xpm"
# define ORG "./textures/bonus/turn_down_1.xpm"
# define EXIT "./textures/bonus/exit.xpm"
# define COINS "./textures/bonus/coin_1.xpm"

//Image and buffer size
# define SPRITE 32
# define BUFFER 1000

//structures declaration
//===========================================//
//struct for image variables
typedef struct s_img
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_img;

//struct for map tokens
typedef struct s_map
{
	int		coins;
	int		exit;
	int		player;
	int		exit_check;
	int		coins_check;
	t_img	coin_img;
	t_img	exit_img;
	t_img	playerleft_img;
	t_img	playerright_img;
	t_img	playerup_img;
	t_img	playerdown_img;
	t_img	floor_img;
	t_img	wall_img;
	t_img	player_img;
}	t_map;

//struct for player(points, position and movement)
typedef struct s_player
{
	int	x;
	int	y;
	int	move_up;
	int	move_down;
	int	move_left;
	int	move_right;
	int	coins_collected;
	int	move_no;
}	t_player;

//struct for x terminal window initialization
typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			length;
	int			height;
	char		**map_array;
	t_map		map;
	t_player	player;
}	t_window;

//utils.c
void	free_image(t_window *window);
void	free_array(char **array);
void	handle_exit(int fd, t_window *window);
void	handle_error(int err_no, char *err_msg, t_window *window);
int		exit_game(t_window *window);

//render.c
t_img	load_image(void *mlx_ptr, char *filepath);
void	img_put(t_window *window, t_img *img_ptr, int y, int x);
void	map_renderer(t_window *window);

//move.c
void	move_up(t_window *window, int y, int x);
void	move_down(t_window *window, int y, int x);
void	move_left(t_window *window, int y, int x);
void	move_right(t_window *window, int y, int x);
int		handle_event(int keysym, t_window *window);

//map_check.c
void	empty_map_check(char *buffer);
void	valid_map_check(char *buffer);

//initialize_game.C
void	init_game(char *buffer);

//initialize_all.c
void	initialize_structure(t_window *window);
void	asset_to_characters(t_window *window);
void	initialize_map(t_window *window);

//game_attributes.c
int		rectangle_check(t_window *window, int height);
int		wall_check(t_window *window, int width, int height);
int		token_check(t_window *window);
void	player_pos(t_window *window);
void	path_check(t_window *window, char **tempbuf, int x, int y);
void	check_attributes(t_window *window, char *buffer);

#endif
