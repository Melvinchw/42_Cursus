#include "libft.h"

int	ft_strlcpy(char *src, char *dst, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[i] != '\0')
		count++;
	if (size < 0)
		return (count);
	while (src[i] != '\0' && size > i - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(count);
}
