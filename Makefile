# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:33:03 by bhennequ          #+#    #+#              #
#    Updated: 2023/03/23 19:51:58 by bhennequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTNAME = libft.a

NAME = push_swap

LIBFTDIR = libft

CC = gcc

SRC = src/main.c src/init.c src/op_stack.c src/sort_big_stack.c src/sort_small_stack.c src/swap.c

CFLAGS = -Wall -Wextra -Werror

OBJSRC = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJSRC}
		cd ${LIBFTDIR} && make all
		${CC} ${OBJSRC} push_swap.h ${LIBFTDIR}/${LIBFTNAME} -o ${NAME}

bonus: 
		cd bonus && make all

clean:
		rm -f src/*.o
		cd ${LIBFTDIR} && make clean
		cd bonus && make clean

fclean: clean
		rm -f ${NAME}
		cd ${LIBFTDIR} && make fclean
		cd bonus && make fclean

re: fclean all
	cd bonus && make re

.PHONY: all bonus clean fclean re
