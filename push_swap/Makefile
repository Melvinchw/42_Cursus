# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <mchua@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 21:00:10 by mchua             #+#    #+#              #
#    Updated: 2024/04/28 11:54:42 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET:= push_swap

SRCS:= algo_utils \
	algorithm \
	check_utils \
	handle_error \
	init_node_utils \
	push_swap \
	push \
	rotate_operations \
	rotate \
	reverse_rotate \
	split_args \
	stack_utils \
	swap

OBJS:= ${SRCS:=.o}

INCLUDE:= libft.h

CC:= cc

CCFLAGS:= -g -Wall -Werror -Wextra -I ${INCLUDE}

LIB:= libft.a

AR:= ar crs

RM:= rm -rf

.PHONY: all clean fclean re

all: ${TARGET}

${TARGET}: ${OBJS} ${LIB}

%.o: %.c
	${CC} ${CCFLAGS} -o $@ -c $^

${LIB}:
	make -C ./libft
	mv ./libft/libft.a .

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}
	${RM} ${LIB}

re: fclean all
