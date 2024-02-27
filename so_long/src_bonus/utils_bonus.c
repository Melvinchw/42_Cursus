/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:07:51 by mchua             #+#    #+#             */
/*   Updated: 2024/01/29 17:07:51 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	img_put(t_window *window, t_img *img_ptr, int y, int x)
{
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
		img_ptr, (x * SPRITE), (y * SPRITE));
}

void	free_image(t_window *window)
{
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[0].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[1].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[2].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[3].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[4].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.coin_img[5].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.floor_img.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.wall_img.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_1[0].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_1[1].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_1[2].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_1[3].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_2[0].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_2[1].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_2[2].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.player_2[3].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.en_img.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->map.exit_img.img_ptr);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

void	handle_error(int err_no, char *err_msg, t_window *window)
{
	if (err_no == 1)
		ft_printf("Input error: %s\n", err_msg);
	else if (err_no == 2)
		ft_printf("File error: %s\n", err_msg);
	else if (err_no == 3)
		ft_printf("Invalid map error: %s\n", err_msg);
	else if (err_no == 4)
		ft_printf("Memory allocation error\n", err_msg);
	if (err_no == 5)
		ft_printf("Game attribute error: %s\n", err_msg);
	handle_exit(3, window);
	exit(0);
}

void	handle_exit(int fd, t_window *window)
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
		if (fd != 3)
		{
			free_image(window);
			mlx_destroy_window(window->mlx_ptr, window->win_ptr);
			mlx_destroy_display(window->mlx_ptr);
			free(window->mlx_ptr);
		}
		free(window);
		exit(0);
	}
}
