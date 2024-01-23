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
} t_map;

//struct for player(points, position and movement)
typedef struct  s_player
{
    int x;
    int y;
    int mvoe_up;
    int move_down;
    int move_left;
    int move_right;
    int coins_collected;
    int move_no;
} t_player;

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
} t_window;

void    free_image(t_window *window)
{
    mlx_destroy_image(window->mlx_ptr, window->map.wall_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.coin_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.floor_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.playerdown_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.playerup_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.playerleft_img.img_ptr);
    mlx_destroy_image(window->mlx_ptr, window->map.playerright_img.img_ptr);
}

//utils.c
void    free_image(t_window *window);
void    free_array(char **array);
void    handle_error(int err_no, char *err_msg);
void    handle_exit(int fd, t_window *window);

//render.c
t_img load_image(void mlx_ptr, char *filepath);
void    img_put(t_window *window, t_img *img_ptr, int y, int x);
void    map_renderer(t_window *window);

//move.c
void    move_up(t_window *window, int y, int x);
void    move_down(t_window *window, int y, int x);
void    move_left(t_window *window, int y, int x);
void    move_right(t_window *window, int y, int x);
int handle_event(int keysym, t_window *window);

//map_check.c
void	empty_map_check(char *buffer);
void	valid_map_check(char *buffer);

//initialize_game.C
void	init_game(char *buffer);

//initialize_all.c
void    initialize_structure(t_window *window);
void    asset_to_characters(t_window window);
void    initialize_map(t_window *window);

//game_attributes.c
void    rectangle_check(t_window *window, int height);
void    wall_check(t_window *window, int width, int height);
void    token_check(t_window *window);
void    player_pos(t_window *window);
void    path_check(t_window *window, char **tempbuf, int x, int y);
void    check_attributes(t_window *window, char *buffer);

//so_long.c
int main (int argc, char **argv);

#endif