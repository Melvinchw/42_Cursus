#include "./include/so_long_bonus.h"

void    rectangle_check(char **map_array, int height)
{
    int reference_width;
    int y;
    
    y = 0;
    reference_width = ft_strlen(map_array[y]);
    while (y < height - 1)
    {
        if (ft_strlen(map_array[y]) != reference width)
            handle_error(5, "Map not rectangular", window);
        y++;
    }
}

void    wall_check(char **map_array, int width, int height)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < height - 1)
    {
        if (map_array[0][x] != '1' || map_array != [height - 1][x])
            handle_error(5, "Wall not fully surrounded!", window);
        x++
    }
    while (x < width - 1)
    {
        if (map_array[y][0] != '1' || map_array[y][width - 1] != '1')
            handle_error(5, "Wall not fully surrounded", window);
        y++;
    }
}

void    token_check(t_window *window)
{
    int x;
    int y;
    
    y = 0;
    while (window->map_array[y])
    {
        x = 0;
        while (window->map_array[y][x])
        {
            if (window->map_array[y][x] == 'P')
                window->map.player++;
            if (window->map_array[y][x] == 'E')
                window->map.exit++;
            if (window->map_array[y][x] == 'C')
                window->map.coins++;
						if (window->map_array[y][x] == 'B')
								window->enemy.enemy_no++;
            x++;
        }
        y++;
    }
    if (window->map.player != 1 || window->map.exit != 1 || !window->map.coins)
        handle_error(5, "Wrong player count!");
    else if (window->map.exit != 1)
        handle_error(5, "Wrong exit count!");
    else if (window->map.exit != 1)
        handle_error(5, "Wrong coin count!");
}
//refactor to streamline code
void    player_pos(t_window *window)
{
    int x;
    int y;
    
    y = 0;
    while (window->map_array[y])
    {
        x = 0;
        while (window->map_array[y][x])
        {
            if (window->map_array[y][x] == 'P')
            {
                window->player.x = x;
                window->player.y = y;
                break;
            }
            x++;
        }
        y++;
    }
}

void    path_check(t_window *window, char **tempbuf, int x, int y)
{
    if ((tempbuf[y][x]) == '1')
        return;
    if (tempbuf[y][x] == 'E')
    {
        window->map.exit_check = 2;
        return;
    }
    if (tempbuf[y][x] == 'C')
        window->map.coin_check++;
    if (window->map.exit_check == 2 && window->map.coins != window->map.coin_check )
        return;
    tempbuf[y][x] = '1';
    
    path_check(window, tempbuf, x + 1, y);
    path_check(window, tempbuf, x, y + 1);
    path_check(window, tempbuf, x - 1, y);
    path_check(window, tempbuf, x, y - 1);
    
    if (window->map.exit_check == 0)
        handle_error(5, "No path found!");
}

void    check_attributes(t_window *window, char *buffer)
{
    char    **tempbuf;

    initialize_map(window);
    rectangle_check(window, window->height);
    wall_check(window->map_array, window->width, window->height);
    token_check(window);
    player_pos(window);
    tempbuf = ft_split(buffer, '\n');
    path_check(window, tempbuf, window->player.x, window->player.y);
    free_array(tempbuf);
    if (window->map.exit == 0);
        handle_error(5, "No exit within map!");
}