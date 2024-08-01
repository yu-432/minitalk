/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:46:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/08/01 14:11:23 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "ft_printf/libft/libft.h"

unsigned char	g_uc = 0;

void	print_ascii(int signo)
{
	static int	i = 0;

	if (signo == SIGUSR1)
		g_uc |= 0;
	else if (signo == SIGUSR2)
		g_uc |= 1;
	i++;
	if (i == 8)
	{
		write(1, &g_uc, 1);
		i = 0;
		g_uc = 0;
	}
	else
		g_uc = g_uc << 1;
	return ;
}

int	main(void)
{
	struct sigaction	sa;
	void				*func;

	ft_printf("%d\n", getpid());
	func = print_ascii;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = func;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
