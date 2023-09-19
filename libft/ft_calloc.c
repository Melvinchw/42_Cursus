#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	i;
	unsigned char	*mem;
	
	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	else
		mem = malloc(nmemb * size);
	while (i < nmemb)//can use ft_memset or ft_bzero here
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
