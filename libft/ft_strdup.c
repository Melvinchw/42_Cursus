#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	int	i;
	int	j;
	char	*str;
	
	i = 0;
	j = 0;
	while (s[i] != '\0')//can use ft_strlen
	{
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i +1))))
		return (NULL);
	while (s[j] != '\0')//can use ft_strcpy
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);	
}
/*
int main ()
{
	int	i;
	const char	*str = "Hello World";
	const char	*ptr;
	
	i = 0;
	while (str[i])
		i++;
	if((ptr = ft_strdup(str)) != NULL)
		printf("%s\n", ptr);
	else
		printf ("Error allocating memory");
	free((void *)ptr);
	return (0);
}
*/
