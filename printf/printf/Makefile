# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 19:46:14 by mchua             #+#    #+#              #
#    Updated: 2023/09/28 19:46:15 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_printf.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putunsigned.c \
	ft_putvoid.c
	
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rc -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: clean fclean re all
