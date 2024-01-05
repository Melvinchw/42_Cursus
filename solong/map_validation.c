/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:39:13 by mchua             #+#    #+#             */
/*   Updated: 2024/01/05 21:57:26 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_map
{
	char    **map;
	int     is_path;
	int     is_collectibles;
	int     is_start;
	int     is_exit;
	char	*map_buffer;
}	t_map;

void	rectangle_checker(t_map map)
{
	int	x;
	int	y;
	int	length;

	y = 0;
	length = ft_strlen(map[x][y]);

	while (map[y][x] != 0)
	{
		x = 0;
		while (map[y][0] != "\n")
			x++;
		if (ft_strlen(map[y][x]) != length)
			handle_error(3);
		y++;
		printf("This map is a rectangle\n");
	}
}

void	
