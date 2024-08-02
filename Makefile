# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 15:23:57 by yooshima          #+#    #+#              #
#    Updated: 2024/08/02 15:01:40 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	= ft_printf/libft/libft


OBJS		= ${*_SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		client server

bonus:		client_bonus server_bonus

client:			client.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o client
server:			server.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o server
client_bonus:	client_bonus.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) client_bonus.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o client_bonus
server_bonus:	server_bonus.c
			$(MAKE) -C ft_printf
			$(CC) $(CFLAGS) server_bonus.c ft_printf/libftprintf.a $(LIBFT_PATH).a -o server_bonus

clean:
			$(MAKE) -C ft_printf clean

fclean:
			$(MAKE) -C ft_printf fclean
			${RM} client client_bonus server server_bonus

re:			fclean all

.PHONY:		all fclean re bonus
