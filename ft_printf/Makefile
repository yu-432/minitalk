# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:59:59 by yooshima          #+#    #+#              #
#    Updated: 2024/08/02 15:02:58 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c put_hex.c put_int_char.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C libft
			${AR} ${NAME} ${OBJS}

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			$(MAKE) -C libft clean


fclean:		clean
			$(MAKE) -C libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
