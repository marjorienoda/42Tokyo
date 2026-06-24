# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 14:08:38 by mnoda-ta          #+#    #+#              #
#    Updated: 2026/06/16 14:08:39 by mnoda-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_MAIN = main.c

SRC_UTILS = utils/bench.c utils/check_inputs.c \
			utils/stack_utils.c utils/stack_init.c \
			utils/utils.c

SRC_OPERATIONS = operations/operations_utils.c operations/index_utils.c \
				 operations/pa_operation.c operations/pb_operation.c \
				 operations/ra_operation.c operations/rb_operation.c \
				 operations/rr_operation.c operations/rra_operation.c \
				 operations/rrb_operation.c operations/rrr_operation.c \
				 operations/sa_operation.c operations/sb_operation.c \
				 operations/ss_operation.c operations/simple_strategy.c \
				 operations/complex_strategy.c operations/medium_utils.c \
				 operations/medium_strategy.c operations/adaptive_strategy.c \
				 operations/disorder.c

SRC_LIBFT = libft/ft_atoil.c libft/ft_isdigit.c \
			libft/ft_printf.c libft/ft_putchar_fd.c \
			libft/ft_putdouble_fd.c libft/ft_putnbr_fd.c \
			libft/ft_strlen.c libft/ft_strncmp.c \
			libft/ft_putstr_fd.c

SRCS = ${SRC_MAIN} ${SRC_UTILS} ${SRC_OPERATIONS} ${SRC_LIBFT}  
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
