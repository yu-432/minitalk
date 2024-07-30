/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:46:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/24 17:51:21 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "./libft/libft.h"

unsigned char uc = 0;
int i = 0;

void print_ascii(int signo, siginfo_t *info, void *v)
{
	(void)v;
	if (info == NULL)
		return ;
	if (signo == SIGUSR1)
		uc |= 0;
	else if (signo == SIGUSR2)
		uc |= 1;
	i++;
	if (i == 8)
	{
		int j = 0;
		while(j < 8)
		{
			printf("%d", (uc >> j) & 1);
			j++;
		}
		printf("%c\n", uc);
		i = 0;
		uc = 0;
	}
	uc = uc << 1;
	return ;
}

int main(void)
{
	struct sigaction sa1;
	void *func;

	printf("%d\n", getpid());
	func = print_ascii;
	memset(&sa1, 0, sizeof(sa1));//change to ft
	sa1.__sigaction_u.__sa_sigaction = func;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa1, NULL);
	while(1)
	{
	}
	return (0);
}