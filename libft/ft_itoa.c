#include "libft.h"

size_t	intcounter(int n)
{
	size_t	i;
	
	i = 1;
	while (n / 10 != 0)
		i++;
	return (i);
}
char	*ft_itoa(int n)
{
//get the number of digits in the int.
//allocate data memory of char.
	size_t	count;
	char	*str_num;
	long int	num;
	
	num = n;
	count = intcounter(n);
	str_num = (char *)malloc((sizeof (char) * count) + 1)
	
	if (n < 0)
	{
		num *= -1;
		count++;
	}
	if(!(str_num = (char *)malloc((sizeof (char) * count) + 1)))
		return (NULL);
	str_num[count] = '\0';
	while (count != 0)
	{
		count--;
		str_num[count] = num % 10 + '0';
		num /= 10;
		
	}
	if (n < 0)
		str_num[0] = '-';
	return(str_num);
}
