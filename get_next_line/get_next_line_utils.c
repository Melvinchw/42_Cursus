#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i +1));
	if (!str)
		return (NULL);
	while (s[j] != '\0')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		string_len;
	char				*memory;
	size_t				i;

	string_len = ft_strlen ((char *)s);
	if (!s || start >= string_len || len == 0)
		return (ft_strdup(""));
	if (len > string_len - start)
		len = string_len - start;
	memory = (char *)(malloc(sizeof (char) * (len + 1)));
	i = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		j;
	int		total_len;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof (char) * (total_len + 1));
	if (!new_string)
		return (NULL);
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
	new_string[total_len] = '\0';
	return (new_string);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i++;
	}
	return (NULL);
}
