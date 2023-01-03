# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:39:34 by avaganay          #+#    #+#              #
#    Updated: 2022/11/23 11:48:49 by avaganay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c	ft_printf_nbr.c	ft_printf_str.c	ft_printf_ptr.c

OBJS = ${SRCS:.c=.o}

CC = gcc

HEAD = ft_printf.h

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = ar rc

RM = rm -f

%.o: %.c  ${HEAD} Makefile
	${CC} ${FLAGS} -I${HEAD} -c $< -o $@

all: ${NAME}

libft: 
	make -C Libft

${NAME}:	libft ${OBJS}
	cp Libft/libft.a ./libftprintf.a
	${LIB} ${NAME} ${OBJS}

clean:		
	${RM}  ${OBJS} a.out
	make clean -C Libft

fclean:	clean 
	${RM} ${NAME} a.out
	make fclean -C Libft

re:	fclean all

.PHONY: all clean fclean re libft

