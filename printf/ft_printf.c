/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:50:28 by mchua             #+#    #+#             */
/*   Updated: 2023/09/24 15:50:29 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	printformat(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunsigned(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'p')
		count += ft_putvoid(va_arg(ap, unsigned long int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += printformat(*format, ap);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	return (count);
}

int main ()
{
    int count;
    int printf_count;
    char	*ptr;
    
    ptr = "Hello";
    count = 0;
    printf_count = 0;
    //Test for %c
    //Printable characters
    ft_printf("============ Test Case 1: %s ============\n", "%c");
    ft_printf("=============== Printables ===============\n");
    count += ft_printf("U_Output: %c\n", 'c');
    printf_count +=printf("E_Output: %c\n", 'c');
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Special Characters
    ft_printf("============ Special ============\n");
    count += ft_printf("U_Output: %c\n", '!');
    printf_count +=printf("E_Output: %c\n", '!');
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    
    ft_printf("============ Non - Printables ============\n");
    count += ft_printf("U_Output: %c\n", '\t');
    printf_count +=printf("E_Output: %c\n", '\t');
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
        
    //Test for %s
    //Empty string
    ft_printf("============ Test Case 2: %s ============\n", "%s");
    ft_printf("=============== Empty String ===============\n");
    count += ft_printf("U_Output: %s\n", "");
    printf_count +=printf("E_Output: %s\n", "");
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Whitespace
    ft_printf("=============== Whitespace ===============\n");
    count += ft_printf("U_Output: %s\n", " ");
    printf_count +=printf("E_Output: %s\n", " ");
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //String with ASCII
    ft_printf("=============== ASCII String ===============\n");
    count += ft_printf("U_Output: %s\n", "Hello World");
    printf_count +=printf("E_Output: %s\n", "Hello World");
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //String with non ASCII
    //String with special characters
    ft_printf("============= Special String =============\n");
    count += ft_printf("U_Output: %s\n", "!@#$%^&");
    printf_count +=printf("E_Output: %s\n", "!@#$%^&");
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    
    //Test for %p
    //Valid memory address
    ft_printf("============ Test Case 3: %s ============\n", "%p");
    ft_printf("=============== Valid Address ===============\n");
    count += ft_printf("U_Output: %p\n", ptr);
    printf_count +=printf("E_Output: %p\n", ptr);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Null ptr
    ft_printf("=============== NULL Pointer ===============\n");
    count += ft_printf("U_Output: %p\n", NULL);
    printf_count +=printf("E_Output: %p\n", NULL);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Test for %d/i
    //Positive integer
    ft_printf("============ Test Case 4: %s ============\n", "%d");
    ft_printf("=============== Positive Int ===============\n");
    count += ft_printf("U_Output: %d\n", 42);
    printf_count +=printf("E_Output: %d\n", 42);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Negative integer
    ft_printf("=============== Negative Int ===============\n");
    count += ft_printf("U_Output: %d\n", -42);
    printf_count +=printf("E_Output: %d\n", -42);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Zero
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %d\n", 0);
    printf_count +=printf("E_Output: %d\n", 0);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Min value
    ft_printf("================== Min Value ==================\n");
    count += ft_printf("U_Output: %d\n", INT_MIN);
    printf_count +=printf("E_Output: %d\n", INT_MIN);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Max value
    ft_printf("================== Max Value ==================\n");
    count += ft_printf("U_Output: %d\n", INT_MAX);
    printf_count +=printf("E_Output: %d\n", INT_MAX);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    
    ft_printf("============ Test Case 5: %s ============\n", "%i");
    ft_printf("=============== Positive Int ===============\n");
    count += ft_printf("U_Output: %i\n", 42);
    printf_count +=printf("E_Output: %i\n", 42);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Negative integer
    ft_printf("=============== Negative Int ===============\n");
    count += ft_printf("U_Output: %i\n", -42);
    printf_count +=printf("E_Output: %i\n", -42);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Zero
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %i\n", 0);
    printf_count +=printf("E_Output: %i\n", 0);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Min value
    ft_printf("================== Min Value ==================\n");
    count += ft_printf("U_Output: %i\n", INT_MIN);
    printf_count +=printf("E_Output: %i\n", INT_MIN);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Max value
    ft_printf("================== Max Value ==================\n");
    count += ft_printf("U_Output: %i\n", INT_MAX);
    printf_count +=printf("E_Output: %i\n", INT_MAX);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    
    //Test for %u
    //Positive integer
    ft_printf("============ Test Case 6: %s ============\n", "%u");
    ft_printf("=============== Positive Int ===============\n");
    count += ft_printf("U_Output: %u\n", 42);
    printf_count +=printf("E_Output: %u\n", 42);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Zero
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %u\n", 0);
    printf_count +=printf("E_Output: %u\n", 0);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Unsigned max value
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %u\n", UINT_MAX);
    printf_count +=printf("E_Output: %u\n", UINT_MAX);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Negative value
    ft_printf("=============== Negative Value ===============\n");
    count += ft_printf("U_Output: %u\n", -1);
    printf_count +=printf("E_Output: %u\n", -1);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Test for %x/%X
    //Positive integer
    ft_printf("============ Test Case 7: %s ============\n", "%x");
    ft_printf("=============== Positive Int ===============\n");
    count += ft_printf("U_Output: %x\n", 18657);
    printf_count +=printf("E_Output: %x\n", 18657);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Negative integer
    ft_printf("=============== Negative Int ===============\n");
    count += ft_printf("U_Output: %x\n", -18657);
    printf_count +=printf("E_Output: %x\n", -18657);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Zero
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %x\n", 0);
    printf_count +=printf("E_Output: %x\n", 0);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Min value
    //Max value
    ft_printf("=============== Max Value ===============\n");
    count += ft_printf("U_Output: %x\n", UINT_MAX);
    printf_count +=printf("E_Output: %x\n", UINT_MAX);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
        
    //Test for %X
    ft_printf("============ Test Case 8: %s ============\n", "%X");
    ft_printf("=============== Positive Int ===============\n");
    count += ft_printf("U_Output: %X\n", 18657);
    printf_count +=printf("E_Output: %X\n", 18657);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Negative integer
    ft_printf("=============== Negative Int ===============\n");
    count += ft_printf("U_Output: %X\n", -18657);
    printf_count +=printf("E_Output: %X\n", -18657);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Zero
    ft_printf("================== Zero ==================\n");
    count += ft_printf("U_Output: %X\n", 0);
    printf_count +=printf("E_Output: %X\n", 0);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Min value
    //Max value
    ft_printf("=============== Max Value ===============\n");
    count += ft_printf("U_Output: %X\n", UINT_MAX);
    printf_count +=printf("E_Output: %X\n", UINT_MAX);
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    //Test for %%
    //Prints %
    ft_printf("============ Test Case 9: %s ============\n", "%%");
    ft_printf("=============== Print %s ===============\n", "%%");
    count += ft_printf("U_Output: %%\n");
    printf_count +=printf("E_Output: %%\n");
    if (count == printf_count)
        ft_printf("====== Success! ======\n\n");
    else
        ft_printf("====== Failure! ======\n\n");
    return (0);
}
