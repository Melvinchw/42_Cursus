//move.c
#include "./include/so_long.h"

void    move_up(t_window *window, int y, int x)
{
    if (window->map_array[y - 1][x] == '0' || window->map_array[y - 1][x] == 'C')//valid move
    {
        window->map_array[y][x] = '0';//change original position to floor
        if (window->map_array[y - 1][x] == 'C')//check if it is coin
            window->player.coins_collected++;//collect coin
        window->player.y--;//put player on new coordinates
        window->map.player_img = window->map.playerup_img;
        window->player.move_no++;
        ft_printf("Move count: %d\n", window->player.move_no);
    }
    else if (window->map_array[y - 1][x] == 'E')
        if (window->map.coin_check == window->player.coins_collected)
            handle_exit(1, window);
}

void    move_down(t_window *window, int y, int x)
{
    if (window->map_array[y + 1][x] == '0' || window->map_array[y + 1][x] == 'C')//valid move
    {
        window->map_array[y][x] = '0';//change original position to floor
        if (window->map_array[y + 1][x] == 'C')//check if it is coin
            window->player.coins_collected++;//collect coin
        window->player.y++;//put player on new coordinates
        window->map.player_img = window->map.playerdown_img;
        window->player.move_no++;
        ft_printf("Move count: %d\n", window->player.move_no);
    }
    else if (window->map_array[y + 1][x] == 'E')
        if (window->map.coin_check == window->player.coins_collected)
            handle_exit(1, window);
}

void    move_left(t_window *window, int y, int x)
{
    if (window->map_array[y][x - 1] == '0' || window->map_array[y][x - 1] == 'C')//valid move
    {
        window->map_array[y][x] = '0';//change original position to floor
        if (window->map_array[y][x - 1] == 'C')//check if it is coin
            window->player.coins_collected++;//collect coin
        window->player.x++;//put player on new coordinates
        window->map.player_img = window->map.playerleft_img;
        window->player.move_no++;
        ft_printf("Move count: %d\n", window->player.move_no);
    }
    else if (window->map_array[y][x - 1] == 'E')
        if (window->map.coin_check == window->player.coins_collected)
            handle_exit(1, window);
}

void    move_right(t_window *window, int y, int x)
{
    if (window->map_array[y][x + 1] == '0' || window->map_array[y][x + 1] == 'C')//valid move
    {
        window->map_array[y][x] = '0';//change original position to floor
        if (window->map_array[y][x + 1] == 'C')//check if it is coin
            window->player.coins_collected++;//collect coin
        window->player.y++;//put player on new coordinates
        window->map.player_img = window->map.playerright_img;
        window->player.move_no++;
        ft_printf("Move count: %d\n", window->player.move_no);
    }
    else if (window->map_array[y][x + 1] == 'E')
        if (window->map.coin_check == window->player.coins_collected)
            exit_handler(1, window);
}

int handle_event(int keysym, t_window *window)
{
    if (keysym == ESC)
        handle_exit(2, window);
    if (keysym == W_KEY && window->map[y - 1][x] != '1')
        move_up(window, window->player.y, window->player.x);
	else if (keysym == S_KEY && window->map_array[y + 1][x] != '1')
        move_down(window, window->player.y, window->player.x);
    else if (keysym == A_KEY && window->map_array[x][x - 1] != '1')
        move_left(window, window->player.y, window->player.x);
    else if (keysym == D_KEY && window->map_array[y][x + 1] != '1')
        move_right(window, window->player.y, window->player.x);
    else
        ft_printf("Invalid move! Try again.\n");
    map_renderer(window);
    return(0);
}