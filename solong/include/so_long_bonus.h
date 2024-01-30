//so_long_bonus.h
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
# define EN_MOVEMENT 10000
# define ANIMATION_COUNTER 30000
# define LIMIT 50

//Process event handler
# define DESTROYWINDOW 17

//Asset filepath
# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/floor.xpm"
# define TURN_RIGHT_1 "./assets/turn_right_1.xpm"
# define TURN_LEFT_1 "./assets/turn_left_1.xpm"
# define TURN_UP_1 "./assets/turn_up_1.xpm"
# define TURN_DOWN "./assets/turn_down.xpm"
# define TURN_RIGHT_2 "./assets/turn_right_2.xpm"
# define TURN_LEFT_2 "./assets/turn_left_2.xpm"
# define TURN_UP_2 "./assets/turn_up_2.xpm"
# define EXIT "./assets/exit.xpm"
# define COINS_1 "./assets/coin_1.xpm"
# define COINS_2 "./assets/coin2.xpm"
# define COINS_3 "./assets/coin3.xpm"
# define COINS_4 "./assets/coin4.xpm"
# define COINS_5 "./assets/coin5.xpm"
# define COINS_6 "./assets/coin6.xpm"
# define EN "./assets/en.xpm"

//Image and buffer size
# define SPRITE 32
# define BUFFER 1000
# define WHITE 0x00FFFFFF

//structures declaration
//===========================================//
//struct for image variables
typedef struct  s_img
{
    void    *img_ptr;
    int x;
    int y;
} t_img;

//struct for map tokens
typedef struct  s_map
{
    int coins;
    int exit;
    int player;
    int exit_check;
    int coins_check;
    t_img coin_img[6];
    t_img exit_img;
    t_img player_1[4];
	t_img player_2[4];
    t_img floor_img;
    t_img wall_img;
	t_img en_img;
} t_map;

//struct for player(points, position and movement)
typedef struct  s_player
{
    int x;
    int y;
	int	direction;
	int	animation_counter;
    int coins_collected;
    int move_no;
} t_player;

typedef struct s_enemy
{
	int	y;
	int	x;
	int	direction;
}t_enemy;

//struct for x terminal window initialization
typedef struct  s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			length;
	int			height;
	int			enemy_no;
	char		**map_array;
    t_map		map;
    t_player    player;
	t_enemy     enemy[LIMIT]; 
} t_window;

//utils_bonus.c
void    free_image(t_window *window);
void    free_array(char **array);
void    handle_error(int err_no, char *err_msg, t_window *window);
void    handle_exit(int fd, t_window *window);

//render_bonus.c
t_img 	load_image(t_window *window, char *filepath);
void    img_put(t_window *window, t_img *img_ptr, int y, int x);
void    display_map(t_window *window);
void    display_enemy(t_window *window);
void	display_moves(t_window *window);

//move_bonus.c
void	move_up(t_window *window, int y, int x);
void	move_down(t_window *window, int y, int x);
void	move_left(t_window *window, int y, int x);
void	move_right(t_window *window, int y, int x);
int		handle_event(int keysym, t_window *window);

//map_check_bonus.c
void	empty_map_check(char *buffer);
void	valid_map_check(char *buffer);

//initialize_game_bonus.c
void	init_game(char *buffer);

//initialize_bonus.c
void    initialize_structure(t_window *window);
void    asset_to_characters(t_window *window);
void    initialize_map(t_window *window);
int		update_enemy(t_window *window);
void    initialize_enemy(t_window *window);

//game_attributes_bonus.c
void    rectangle_check(t_window *window, int height);
void    wall_check(t_window *window, int width, int height);
void    token_check(t_window *window);
void    player_pos(t_window *window);
void    path_check(t_window *window, char **tempbuf, int x, int y);
void    check_attributes(t_window *window, char *buffer);

//enemy_bonus.c
void	collision_check(t_window *window);
void	enemy_new_pos(t_enemy enemy);
void	enemy_change_direction(t_enemy enemy);
void	move_enemy(t_window *window);
int		enemy_move_valid(t_window *window);

#endif