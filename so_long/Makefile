# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:27:16 by mchua             #+#    #+#              #
#    Updated: 2024/02/19 21:57:08 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET:=so_long
TARGET_BONUS:=so_long_bonus
SRCS:= src/game_attributes.c \
		src/initialize_all.c \
		src/initialize_game.c \
		src/map_check.c \
		src/move.c \
		src/render.c \
		src/so_long.c \
		src/utils.c
SRCS_BONUS:= src_bonus/check_game_attributes_bonus.c \
				src_bonus/enemy_bonus.c \
				src_bonus/game_attributes_bonus.c \
				src_bonus/initialize_bonus.c \
				src_bonus/initialize_game_bonus.c \
				src_bonus/map_check_bonus.c \
				src_bonus/move_bonus.c \
				src_bonus/render_bonus.c \
				src_bonus/so_long_bonus.c \
				src_bonus/utils_bonus.c \

OBJS:= ${SRCS:.c=.o}
OBJS_BONUS:=${SRCS_BONUS:.c=.o}
LIB:= libft.a mlx.a
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
	rm -rf libft.a
	rm -rf mlx.a

fclean: clean
	rm -rf ${TARGET}
	rm -rf ${TARGET_BONUS}

re: fclean all
