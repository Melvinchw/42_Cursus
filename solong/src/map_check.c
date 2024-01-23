//map_check.c
#include "so_long.h"

void	empty_map_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer [i + 1] == '\n')
		{
			free(buffer);
			handle_error(2, "Empty Line!'\n'");
		}
		i++;
	}
}

void	valid_map_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P' || buffer[i] == 'E' || buffer[i] == '1'
			|| buffer[i] == 'C' || buffer[i] == '0')
			i++;
		else
		{
			free(buffer);
			handle_error(2, "Invalid characters!");
		}
	}
}
