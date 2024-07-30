# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 15:23:57 by yooshima          #+#    #+#              #
#    Updated: 2024/05/08 10:31:07 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME		= client
S_NAME		= server
LIBFT_PATH	= libft

OBJS		= ${*_SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${C_NAME} ${S_NAME}

client:	client.c
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) client.c -o client
server:	server.c
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) server.c -o server

clean:
			$(MAKE) -C $(LIBFT_PATH) clean

fclean:
			$(MAKE) -C $(LIBFT_PATH) fclean
			${RM} ${C_NAME} ${S_NAME}

re:			fclean all

.PHONY:		all fclean re bonus
