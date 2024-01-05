# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mertan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 17:43:49 by mertan            #+#    #+#              #
#    Updated: 2023/09/13 18:25:10 by mertan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS += ftp_itoa.c ft_pchar.c ft_pptr.c ft_numlen.c ft_phexlu.c \
		ft_printf.c ft_pstring.c ft_uitoa.c

SRCS += get_next_line.c get_next_line_utils.c

BSRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS	= ${SRCS:.c=.o}
BONUS	= ${BSRC:.c=.o}
NAME	= libft.a
LIBC	= ar rc
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

all: ${NAME} bonus

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: ${NAME} ${BONUS}
		${LIBC} ${NAME} ${BONUS}

.PHONY: all clean fclean re bonus