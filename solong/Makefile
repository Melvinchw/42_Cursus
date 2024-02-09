# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:27:16 by mchua             #+#    #+#              #
#    Updated: 2024/02/09 19:08:46 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET:=so_long
TARGET_BONUS:=so_long_bonus
SRCS:= $(wildcard ./src/*.c)
SRCS_BONUS:= $(wildcard ./src_bonus/*.c)
OBJS:= ${SRCS:.c=.o}
OBJS_BONUS:=${SRCS_BONUS:.c=.o}
LIB:= libft.a libmlx_Linux.a
CC:=cc
CFLAGS:= -Wall -Werror -Wextra -Iinclude -Imlx -Ilibft
MLXFLAGS:= -lm -lX11 -lXext -lbsd

.PHONY: all clean fclean re

all: ${TARGET} ${TARGET_BONUS}

${TARGET}: ${OBJS} ${LIB}
	${CC} ${CFLAGS} ${OBJS} ${LIB} ${MLXFLAGS} -o ${TARGET}

${TARGET_BONUS}: ${OBJS_BONUS} ${LIB}
	${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB} ${MLXFLAGS} -o ${TARGET_BONUS}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<

libft.a:
	make -C ./libft
	mv ./libft/libft.a .

clean:
	rm -rf ${OBJS}
	rm -rf ${OBJS_BONUS}

fclean: clean
	rm -rf ${TARGET}
	rm -rf ${TARGET_BONUS}

re: fclean all
