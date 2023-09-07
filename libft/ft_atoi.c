#include "libft.h"

int ft_isspace(char *str)
{
	int	i;
    
	i = 0;
	while((str[i] == 32) || str[i] > 8 && str[i] < 14)
	i++;
	return (i);
}

int ft_negative(char *str)
{
	int i;
	int count;
	i = 0;
	count = ft_isspace(str);
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 43)
			return (1);
	}
	return (-1);
}

int ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = ft_isspace(str);
	neg = ft_negative(str);
	result = 0;
	i++;

	while (str[i] > 47 && str[i] < 58)
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * neg);
}
/*
int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("input is\d\n", argv[1]);
		printf("result is\d\n", ft_atoi(argv[1]));
	}
	else
	printf("\n");
	return (0);
}*/
