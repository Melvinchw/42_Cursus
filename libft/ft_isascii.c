#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 256)
		return (1);
	return (0);
}
