//so_long_bonus.h
#ifndef SO_LONG_H
# define SO_LONG_H

//library inclusion
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
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

//Process event handler
# define DESTROYWINDOW 17

//Asset filepath
# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/floor.xpm"
# define TURN_RIGHT "./assets/turn_right.xpm"
# define TURN_LEFT "./assets/turn_left.xpm"
# define TURN_UP "./assets/turn_up.xpm"
# define TURN_DOWN "./assets/turn_down.xpm"
# define EXIT "./assets/exit.xpm"
# define COINS "./assets/coins.xpm"
# define EN_UP "./assets/en_up.xpm"
# define EN_DOWN "./asset/en_down.xpm"
# define EN_LEFT "./asset/en_left.xpm"
# define EN_RIGHT "./asset/en_right.xpm"

//Image and buffer size
# define SPRITE 32
# define BUFFER 1000

//structures declaration
//===========================================//
//struct for image variables
typedef struct  s_img
{
    void    img_ptr;
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
    t_img coin_img;
    t_img exit_img;
    t_img playerleft_img;
		t_img playerright_img;
		t_img playerup_img;
		t_img playerdown_img;
    t_img floor_img;
    t_img wall_img;
		t_img player_img;
		t_img en_right_img;
		t_img en_left_img;
		t_img en_up_img;
		t_img en_down_img;
} t_map;

//struct for player(points, position and movement)
typedef struct  s_player
{
    int x;
    int y;
    int move_up;
    int move_down;
    int move_left;
    int move_right;
    int coins_collected;
    int move_no;
} t_player;

typedef struct s_enemy
{
	int y;
	int x;
  int dir;
	int enemy_no;
}t_enemy;

//struct for x terminal window initialization
typedef struct  s_window
{
    int mlx_ptr;
    int win_ptr;
    int length;
    int height;
    char    **map_array;
    t_map   map;
    t_player    player;
		t_enemy     enemy; 
} t_window;

//utils_bonus.c
void    free_image(t_window *window);
void    free_array(char **array);
void    handle_error(int err_no, char *err_msg);
void    handle_exit(int fd, t_window *window);

//render_bonus.c
t_img load_image(void mlx_ptr, char *filepath);
void    img_put(t_window *window, t_img *img_ptr, int y, int x);
void    map_renderer(t_window *window);
void    en_renderer(t_window *window);
void	render_moves(t_window *window);

//move_bonus.c
void    move_up(t_window *window, int y, int x);
void    move_down(t_window *window, int y, int x);
void    move_left(t_window *window, int y, int x);
void    move_right(t_window *window, int y, int x);
int handle_event(int keysym, t_window *window);

//map_check_bonus.c
void	empty_map_check(char *buffer);
void	valid_map_check(char *buffer);

//initialize_game_bonus.c
void	init_game(char *buffer);

//initialize_bonus.c
void    initialize_structure(t_window *window);
void    asset_to_characters(t_window window);
void    initialize_map(t_window *window)
int update_enemy(t_window *window);
void    initialize_en(t_window *window);

//game_attributes_bonus.c
void    rectangle_check(char **map_array, int height);
void    wall_check(char **map_array, int width, int height);
void    token_check(t_window *window);
void    player_pos(t_window *window);
void    path_check(t_window *window, char **tempbuf, int x, int y);
void    check_attributes(t_window *window, char *buffer);

//enemy_bonus.c
void    collision_check(t_window *window, t_enemy enemy, t_player, player);
void    new_en_pos(t_enemy enemy);
void    en_change_dir(t_enemy enemy);
void    move_enemy(t_window *window, t_enemy enemy);
void    en_valid_move(t_window *window, t_enemy enemy);

#endif