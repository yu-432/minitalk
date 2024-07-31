# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 15:23:57 by yooshima          #+#    #+#              #
#    Updated: 2024/07/31 18:30:25 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME		= client
S_NAME		= server
LIBFT_PATH	= ft_printf/libft/libft


OBJS		= ${*_SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${C_NAME} ${S_NAME}

client:	client.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o client
server:	server.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o server

clean:
			$(MAKE) -C ft_printf clean

fclean:
			$(MAKE) -C ft_printf fclean
			${RM} ${C_NAME} ${S_NAME}

re:			fclean all

.PHONY:		all fclean re bonus
