# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 20:46:50 by mchua             #+#    #+#              #
#    Updated: 2023/09/05 20:46:52 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c

NAME = libft.a

BIN = main

CC = clang

CC_FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(BIN)


$(BIN): $(NAME)
	$(CC) $(CC_FLAGS) -o $@ $(SRCS)

$(NAME): $(OBJS)
	ar rc -o $(NAME) $(OBJS)
	ranlib $(NAME)
%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all

.PHONY: clean flcean re
