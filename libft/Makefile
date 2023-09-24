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
SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_calloc.c \
	ft_strlcat.c \
	ft_memmove.c \
	ft_strnstr.c

BONUS_SRCS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
			

NAME = libft.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc -o $(NAME) $(OBJS)
	ranlib $(NAME)
	
%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	
fclean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	rm -f $(NAME)
re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc -o $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: clean flcean re
