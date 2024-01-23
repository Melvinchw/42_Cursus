//initialize_all.c
#include "./include/so_long.h"

void    initialize_structure(t_window *window)
{
    window->map.coins = 0;
    window->map.exit = 0;
    window->map.player = 0;
    window->map.exit_check = 0;
    window->map.coins_check = 0;
    window->player.x = 0;
    window->player.y = 0;
    window->player.coins_collected = 0;
    window->player.move_no = 0;
    window->width = 0;
    window->height = 0;
    window->map_array = 0;
}

void    asset_to_characters(t_window window)
{
    window->map.coin_img = load_image(window->mlx_ptr, COINS);
    window->map.exit_img = load_image(window->mlx_ptr, EXIT);
    window->map.wall_img = load_image(window->mlx_ptr, FLOOR);
    window->map.floor_img = load_image(window->mlx_ptr, WALL);
    window->map.playerright_img = load_image(window->mlx_ptr, TURN_RIGHT);
    window->map.playerleft_img = load_image(window->mlx_ptr, TURN_LEFT);
    window->map.playerup_img = load_image(window->mlx_ptr, TURN_UP);
    window->map.playerdown_img = load_image(window->mlx_ptr, TURN_DOWN);
		window->map.player_img = load_image(window->mlx_ptr, TURN_DOWN);
}

//passed in window and buffer, map array filled with ft_split map
//need a tempbuffer to manipulate map
//map_array[column][row] = map_array[height][width]
void    initialize_map(t_window *window)
{
    window->height = 0;
    while (window->map_arr[window->height])
    {
        window->width = 0;
        while (window->map.map_array[window->width][window->height])
            window->width++;
        window->height++;
    }
}