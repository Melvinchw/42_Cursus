//render.c
#include "./include/so_long.h"
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