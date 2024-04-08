# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 20:21:27 by mchua             #+#    #+#              #
#    Updated: 2024/04/04 21:58:22 by mchua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
INCLUDE:=./include
TARGET:= pipex
SRCS:=pipex process utils commands
OBJS:=${SRCS:=.o}
LIB:=libft.a
CC:=cc
CFLAGS:= -Wall -Werror -Wextra -I ${INCLUDE}
AR:=ar crs
RM:= rm -rf

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS} ${LIB}
	${CC} $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
libft.a:
	make -C ./libft
	mv ./libft/libft.a .
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(TARGET)
	$(RM) $(LIB)
re: fclean all
