#include "so_long.h"

void	init_game(char *buffer)
{
	t_window	*window;

	empty_map_check(buffer);
	valid_map_check(buffer);
	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		handle_error(7, "Allocation error");
	initialize_structure(window);
	window->map_array = ft_split(buffer, '\n');
	check_game_attributes(window, buffer);
	free(buffer);
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			window->width * SPRITE, window->height * SPRITE, "SOOO_LOONG!");
	asset_to_characters(window);
	render_map(window);
	mlx_key_hook(window->win_ptr, key_hook, window);
	mlx_hook(window->win_ptr, DESTROYWINDOW, 0, handle_exit(3, window), window);
	mlx_loop(window->mlx_ptr);
}
