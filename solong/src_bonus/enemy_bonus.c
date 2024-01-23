//enemy_bonus.c
#include "./include/so_long_bonus.h"

void    collision_check(t_window *window, t_enemy enemy, t_player, player)
{
    int i;
    
    i = 0;
    while (i < window->enemy.enemy_no)
    {
        if (enemy[i].y == player.y && enemy[i].x == player.x)
            handle_exit(2);
    }
}

void    new_en_pos(t_enemy enemy)
{
    if (enemy.dir == move_up)
        enemy.y--;
    else if (enemy.dir == move_down)
        enemy.y++;
    else if (enemy.dir == move_left)
        enemy.x--;
    else if (enemy.dir == move_right)
        enemy.x++;
}

void    en_change_dir(t_enemy enemy)
{
    if (enemy.dir < 3)
        enemy.dir++;
    else
        enemy.dir == 0;
}

void    move_enemy(t_window *window, t_enemy enemy)
{
    static   int count;
    int i;
    
    i = 0;
    count++;
    if (count < EN_MOVEMENT)
        return;
    while (i < window->enemy.enemy_no)
    {
        if (en_valid_move(window, window->enemy[i]))
        {
            img_put(window, window->map.floor_img, y, x);
            new_en_pos(window->enemy[i]);
        }
        else
        {
            img_put(window, window->map.floor_img, y, x);
            en_change_dir(window->enemy[i]);
        }
        en_renderer(window);
				i++;
    }
    count = 0;
}

//return 1 to show that it is a valid move
void    en_valid_move(t_window *window, t_enemy enemy)
{
    if (enemy.move_up && !ft_strrchr("1CE", window->map_array[y - 1][x]))
        return(1);
    if (enemy.move_down && !ft_strrchr("1CE", window->map_array[y + 1][x]))
        return(1);
    if (enemy.move_right && !ft_strrchr("1CE", window->map_array[y][x + 1]))
        return(1);
    if (enemy.move_right && !ft_strrchr("1CE", window->map_array[y][x - 1]))
        return(1);
    return (0);
}