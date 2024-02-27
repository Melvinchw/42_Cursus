/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:39:47 by mchua             #+#    #+#             */
/*   Updated: 2024/01/31 09:39:47 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

//enemy
# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define EN_MOVEMENT 1500
# define ANIMATION_COUNTER 800
# define LIMIT 50

//Process event handler
# define DESTROYWINDOW 17

//Asset filepath
# define WALL	"./assets/bonus/wall.xpm"
# define FLOOR	"./assets/bonus/floor.xpm"
# define TURN_RIGHT_1	"./assets/bonus/turn_right_1.xpm"
# define TURN_LEFT_1	"./assets/bonus/turn_left_1.xpm"
# define TURN_UP_1	"./assets/bonus/turn_up_1.xpm"
# define TURN_RIGHT_2	"./assets/bonus/turn_right_2.xpm"
# define TURN_LEFT_2	"./assets/bonus/turn_left_2.xpm"
# define TURN_UP_2	"./assets/bonus/turn_up_2.xpm"
# define EXIT	"./assets/bonus/exit.xpm"
# define COINS_1	"./assets/bonus/coin_1.xpm"
# define COINS_2	"./assets/bonus/coin_2.xpm"
# define COINS_3	"./assets/bonus/coin_3.xpm"
# define COINS_4	"./assets/bonus/coin_4.xpm"
# define COINS_5	"./assets/bonus/coin_5.xpm"
# define COINS_6	"./assets/bonus/coin_6.xpm"
# define TURN_DOWN	"./assets/bonus/turn_down_1.xpm"
# define EN	"./assets/bonus/en.xpm"

//Image and buffer size
# define SPRITE 32
# define BUFFER 1000
# define WHITE 0xFFFFF

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
	t_img	coin_img[6];
	t_img	exit_img;
	t_img	player_1[4];
	t_img	player_2[4];
	t_img	floor_img;
	t_img	wall_img;
	t_img	en_img;
}	t_map;

//struct for player(points, position and movement)
typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
	int	animation_counter;
	int	coins_collected;
	int	move_no;
}	t_player;

typedef struct s_enemy
{
	int	y;
	int	x;
	int	dir;
}	t_enemy;

//struct for x terminal window initialization
typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			length;
	int			height;
	int			enemy_no;
	char		**map_array;
	t_map		map;
	t_player	player;
	t_enemy		enemy[LIMIT];
}	t_window;

//utils_bonus.c
void	img_put(t_window *window, t_img *img_ptr, int y, int x);
void	free_image(t_window *window);
void	free_array(char **array);
void	handle_error(int err_no, char *err_msg, t_window *window);
void	handle_exit(int fd, t_window *window);

//render_bonus.c
void	display_map(t_window *window);
void	display_enemy(t_window *window);
void	display_moves(t_window *window);
void	display_coins(t_window *window, bool start);
void	display_player(t_window *window, t_player player);

//move_bonus.c
void	move_up(t_window *window, int y, int x);
void	move_down(t_window *window, int y, int x);
void	move_left(t_window *window, int y, int x);
void	move_right(t_window *window, int y, int x);
void	update_pos(t_window *window, int dir, int y, int x);

//map_check_bonus.c
void	empty_map_check(char *buffer);
void	valid_map_check(char *buffer);

//initialize_game_bonus.c
void	init_game(char *buffer);
int		handle_event(int keysym, t_window *window);
int		update_enemy(t_window *window);
int		exit_game(t_window *window);

//initialize_bonus.c
t_img	load_image(t_window *window, char *filepath);
void	initialize_structure(t_window *window);
void	asset_to_characters(t_window *window);
void	initialize_map(t_window *window);
void	initialize_enemy(t_window *window);

//game_attributes_bonus.c
int		rectangle_check(t_window *window, int height);
int		wall_check(t_window *window, int width, int height);
int		token_check(t_window *window);
void	player_pos(t_window *window);
void	path_check(t_window *window, char **tempbuf, int x, int y);
void	check_attributes(t_window *window, char *buffer);

//enemy_bonus.c
void	collision_check(t_window *window);
void	enemy_new_pos(t_enemy *enemy);
void	enemy_change_direction(t_window *window, t_enemy *enemy);
void	move_enemy(t_window *window);
int		enemy_move_valid(t_window *window, t_enemy enemy);

#endif
