//render_bonus.c
#include "./include/so_long_bonus.h"

t_img load_image(void mlx_ptr, char *filepath)
{
    t_img   img;
    
    img.img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &img.x, &img.y);
    return(img);
}

void    img_put(t_window *window, t_img *img_ptr, int y, int x)
{
    mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img_ptr, (x * SPRITE), (y * SPRITE));
}

void    map_renderer(t_window *window)
{
    int y;
    int x;
    
    y = 0;
    while (window->map_array[y])
    {
        x = 0;
        while (window->map_array[y][x])
        {
            if (window->map_array[y][x] == '1')
                img_put(window, window->map.wall_img, y, x);
            else if (window->map_array[y][x] == 'C')
                img_put(window, window->map.coin_img, y, x);
            else if (window->map_array[y][x] == '0')
                img_put(window, window->map.floor_img, y, x);
            else if (window->map_array[y][x] == 'E')
                img_put(window, window->map.exit_img, y, x);
        }
    }
    img_put(window, window->map.player_img, window->player.y, window->player.x);
}

void    en_renderer(t_window *window)
{
    int i;
    
    i = 0;
    while (i < window->enemy.enemy_no)
    {
        if (window->enemy[i].dir == MOVE_UP)
            img_put(window, window->map.up_img, window->enemy.y, window->enemy.x);
        else if (window->enemy[i].dir == MOVE_DOWN)
            img_put(window, window->map.down_img, window->enemy.y, window->enemy.x);
        else if (window->enemy[i].dir == MOVE_LEFT)
            img_put(window, window->map.left_img, window->enemy.y, window->enemy.x);
        else if (window->enemy[i].dir == MOVE_RIGHT)
            img_put(window, window->map.right_img, window->enemy.y, window->enemy.x);
        i++;
    }
}
void	render_moves(t_window *window)
{
	char	*move_no;

	move_no = ft_itoa(window->player.move_no);
	mlx_string_put(window->mlx_ptr, window->win_ptr, 16, 16, WHITE, "Moves: ");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 55, 16, WHITE, move_no);
	free(move_no);
}