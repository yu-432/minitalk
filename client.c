/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/23 21:59:52 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "./libft/libft.h"

bool send_c(pid_t pid, char c)
{
	int i;
	int bit;
	unsigned char u_char;
	
	u_char = c;
	i = 7;
	while(i >= 0)
	{
		usleep(1000);
		bit = (u_char >> i) & 1;
		printf("%d", bit);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		i--;
	}
	printf(" = %c\n", c);
	return (0);
}

int main(int argc, char *argv[])
{
	(void)argc;
	pid_t pid;
	char *str;

	pid = atoi(argv[1]);
	str = argv[2];
	while(*str)
	{
		send_c(pid, *str);
		str++;
	}
	return (0);
}