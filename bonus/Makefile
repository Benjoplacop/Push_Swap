# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:54:18 by bhennequ          #+#    #+#              #
#    Updated: 2023/03/16 15:59:21 by bhennequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTNAME = libft.a

NAME = checker

LIBFTDIR = ../libft

CC = gcc

SRC = checkers.c init.c mainBonus.c op_Stack.c swap.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror

OBJSRC = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJSRC}
		${CC} ${OBJSRC} checker.h ${LIBFTDIR}/${LIBFTNAME} -o ${NAME}

clean:
	rm -f *.o
	cd ${LIBFTDIR} && make clean

fclean: clean
		rm -f ${NAME}

re: fclean all
