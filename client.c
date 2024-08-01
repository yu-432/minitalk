/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/08/01 14:08:45 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf/libft/libft.h"

bool	send_c(pid_t pid, char c)
{
	unsigned char	u_char;
	int				i;
	int				bit;

	u_char = c;
	i = 7;
	while (i >= 0)
	{
		usleep(50);
		bit = (u_char >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		i--;
	}
	return (0);
}

int	is_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (-1);
		i++;
	}
	return (ft_atoi(pid));
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc < 3)
	{
		ft_putstr_fd("Error: Incorrect arguments\n", 2);
		return (1);
	}
	pid = is_pid(argv[1]);
	if (pid == -1 || kill(pid, 0) == -1)
	{
		ft_putstr_fd("Error: Invalid pid\n", 2);
		return (1);
	}
	while (*argv[2])
	{
		send_c(pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}
