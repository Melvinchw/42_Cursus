/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:42:54 by mchua             #+#    #+#             */
/*   Updated: 2023/09/05 18:42:58 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	LIBFT_H
# define	LIBFT_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
void	*ft_memset(void	*s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_strlcpy(char *src, char *dst, int size);
int	ft_toupper(int c);
int	ft_toupper(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(char *s1, char *s2, int n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
int	ft_atoi(char *str);

#endif

