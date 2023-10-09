#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}


char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int		string_len;
	char				*memory;
	size_t				i;

	i = 0;
	string_len = ft_strlen ((char *)s);
	if (!s || start >= string_len || len == 0)
		return (0);
	if (len > string_len - start)
		len = string_len - start;
	memory = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!memory)
		return (NULL);
	while (i < len)
	{
		memory[i] = s[start];
		i++;
		start++;
	}
	memory[i] = '\0';
	return (memory);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)	
			return (NULL);
		s1[0] = 0;
	}
	new_string = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (ft_free(&s1));
	while (i < ft_strlen(s1))
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	free(s1);
	return (new_string);
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
