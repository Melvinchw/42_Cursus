#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*buffer;

	if (argc != 2)
		handle_error(1, "Incorrect number of input");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 4))
		handle_error(2, "Wrong file format");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error(8, "Error opening file");
	buffer = ft_calloc(BUFFER + 1, sizeof(char));
	if (!buffer)
		return (-1);
	if (read(fd, buffer, BUFFER) <= 0)
	{
		free(buffer);
		handle_error(2, "Empty map file!");
		return (-1);
	}
	init_game(buffer);
	return (0);
}
