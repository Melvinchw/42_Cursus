#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	string_len;
	unsigned int	i;
	char			*result;
	
	string_len = ft_strlen((char *)s);
	i = 0;
	if (!s)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	result = ft_strdup(s);
	while (s[i] != '\0')
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	return (result); 
}
