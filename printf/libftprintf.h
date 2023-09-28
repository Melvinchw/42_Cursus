/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:29:08 by mchua             #+#    #+#             */
/*   Updated: 2023/09/27 20:29:09 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int n);
int	ft_putvoid(unsigned long int n);

#endif
