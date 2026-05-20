# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 10:36:10 by mnoda-ta          #+#    #+#              #
#    Updated: 2026/05/13 10:36:12 by mnoda-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_MAIN = ft_printf.c

SRC_UTILS = utils/ft_putchar.c	utils/ft_putstr.c \
			utils/ft_putnbr.c utils/ft_putnbr_base.c \
			utils/ft_strlen.c utils/ft_putuint.c \
			utils/ft_putptr.c

SRCS = ${SRC_MAIN} ${SRC_UTILS}
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

%.o: %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
		ar rcs ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
