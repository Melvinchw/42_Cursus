//utils_bonus.c
#include "./include/so_long_bonus.h"

void    free_image(t_window *window)
{
    mlx_destroy_iamge(window->mlx_ptr, window->map.coin_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.floor_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.wall_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.playerup_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.playerdown_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.playerleft_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.playerright_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->map.player_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->enemy.up_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->enemy.down_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->enemy.left_img.img_ptr);
    mlx_destroy_iamge(window->mlx_ptr, window->enemy.right_img.img_ptr);
}

void    free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free (array[i]);
        i++;
    }
    free(array);
}

void    handle_error(int err_no, char *err_msg)
{
    if (err_no == 1)
        ft_printf("Input error: %s\n", err_msg);
    else if (err_no == 2)
        ft_printf("File format error: %s\n", err_msg);
    else if (err_no == 3)
        ft_printf("Invalid map error: %s\n", err_msg);
    else if (err_no == 4)
        ft_printf("Memory allocation error\n", err_msg);
    exit(0);
    if (err_no == 5)
        ft_printf("Game attribute error: %s\n", err_msg);
    handle_exit(3, window);
    exit(0);
}

void    handle_exit(int fd, t_window *window)
{
    if (window->map_array)
        free_array(window->map_array);
    if (fd == 1)
        ft_printf("You win!\n");
    if (fd == 2)
        ft_printf("You lose!!\n");
    if (fd != 0)
    {
       ft_printf("Closing game. Goodbye!\n");
       free_image(window);
       mlx_destroy_window(window->mlx_ptr, window->win_ptr);
       mlx_destroy_display(window->mlx_ptr);
       exit(0);
    }
}