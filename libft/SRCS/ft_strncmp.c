#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;

	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] !='\0' && i != n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i])
}
/*
int main (int argc, char **argv)
{
	int	result;

	if (argc == 4)
	{
		results = ft_strncmp(argv[1], argv[2], argv[3]);
		if (results < 0)
			printf("smaller\n");
		else if (results > 0)
			printf("larger\n");
		else
			printf("same\n");
	}
	else
		printf("\n");
	return (0);
}*/
