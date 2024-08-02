/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:13 by yooshima          #+#    #+#             */
/*   Updated: 2024/08/02 14:04:06 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include "ft_printf/libft/libft.h"

bool	send_c(pid_t pid, char c)
{
	unsigned char	uc;
	int				i;
	int				bit;
	int				kill_res;

	uc = c;
	i = 7;
	while (i >= 0)
	{
		usleep(200);
		bit = (uc >> i) & 1;
		if (bit == 0)
			kill_res = kill(pid, SIGUSR1);
		else if (bit == 1)
			kill_res = kill(pid, SIGUSR2);
		if (kill_res != 0)
			return (1);
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
	int		err;

	if (argc != 3)
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
		err = send_c(pid, *argv[2]);
		if (err)
		{
			ft_putstr_fd("Error: Server closed\n", 2);
			return (1);
		}
		argv[2]++;
	}
	return (0);
}
