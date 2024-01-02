/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:04:04 by mchua             #+#    #+#             */
/*   Updated: 2024/01/02 22:03:35 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "./minilibx/mlx.h"

typedef struct s_img
{
	void *new_img;
	char *add;
	int bpp;
	int linelength;
	int endian;
}t_img;

typedef struct s_data
{
	void *mlx_ptr;
	int *win_ptr;
	t_img img;
}t_data;

//encoding the color values
int trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void own_pix_put(t_img image, int x, int y, int colour)
{
	int coordinates;

	coordinates = image.linelength * x + ((y * image.bpp) / 8);
	*((unsigned int *)(coordinates + image.add)) = colour;
}
//to render image
void color_screen(t_data *data, int colour)
{
	int	x;
	int	y;

	x = 0;
	while (y < 1920)
	{
		y = 0;
		while (x < 1080)
		{
			own_pix_put(data->img, x, y, colour);
			x++;
		}
		y++;
	}
}

int event_handler(int keysym, t_data *data)
{
//close window when escape is pressed
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//Change window screen's color
	if (keysym == XK_r || keysym == XK_R)
		color_screen(data, 0xff0000);
	if (keysym == XK_g || keysym == XK_G)
		color_screen(data, 0xff00);
	if (keysym == XK_b || keysym == XK_B)
		color_screen(data, 0xff);
	mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img.new_img, 0, 0);
	return(0);
}

int main()
{
	t_data data;

//Initialize X-System
	data.mlx_ptr = mlx_init;
	if (data.mlx_ptr == NULL)
		return (1);
//Create new window
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "My Coloring Book");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
//setup new image
	data.img.new_img = mlx_new_image(data.mlx_ptr, 1920, 1080); //returns address to pointer of image
	data.img.add = mlx_get_data_addr(data.img.new_img, &data.img.bpp, &data.img.linelength, &data.img.endian);
//Setup hooks
	mlx_key_hook(data.win_ptr, &event_handler, &data);
//Setup event loop
	mlx_loop(data.mlx_ptr);

//Destroy connection and free pointer after loop exited
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return 0;
}
