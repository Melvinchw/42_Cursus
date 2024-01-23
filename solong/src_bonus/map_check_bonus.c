//map_check_bonus.c
#include "./include/so_long_bonus.h"

void	empty_map_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer [i + 1] == '\n')
		{
			free(buffer);
			handle_error(3, "Empty Line!");
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
				|| buffer[i] == 'C' || buffer[i] == '0' || buffer[i] == 'B')
			i++;
		else
		{	
			free[buffer];
			handle_error(3, "Invalid characters!");
		}
	}
}