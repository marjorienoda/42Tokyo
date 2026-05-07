# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/07 15:04:16 by mnoda-ta          #+#    #+#              #
#    Updated: 2026/05/07 15:04:23 by mnoda-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
        ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

PART3 = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
        ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
        ft_lstmap.c

SRC = ${PART1} ${PART2} ${PART3}

OBJS = ${SRC:.c=.o}

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
