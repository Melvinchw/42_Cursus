#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*test case for strlen
//this test case can only accomodate up to 9 no ascii table. Need to find a way to make sure it can do more than that using write function.
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putchar(ft_strlen(argv[1]) + 48);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}*/
