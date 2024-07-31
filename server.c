/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:46:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/31 18:56:16 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "ft_printf/libft/libft.h"

unsigned char uc = 0;

void print_ascii(int signo, siginfo_t *info, void *v)
{
	static int i = 0;
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
		write(1, &uc, 1);
		i = 0;
		uc = 0;
	}
	else
		uc = uc << 1;
	return ;
}

int main(void)
{
	struct sigaction sa1;
	void *func;

	printf("%d\n", getpid());
	func = print_ascii;
	ft_memset(&sa1, 0, sizeof(sa1));//change to ft
	sa1.sa_sigaction = func;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa1, NULL);
	while(1)
	{
	}
	return (0);
}