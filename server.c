/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:46:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/08/02 17:01:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"

void	print_ascii(int signo)
{
	static int				i = 0;
	static unsigned char	uc = 0;

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

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_handler = print_ascii;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
