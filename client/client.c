/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:43 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/25 22:27:57 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../lib/include/libft.h"
#include "../lib/include/ft_printf.h"
#include <stdio.h>
# define PID_MAX 32768
// ./client 12345 abcde

void	err_usage(void)
{
	write(2, "Wrong argument! Please check usage.\n"
		"Usage: ./client [server PID] [message]\n", 76);
	exit(1);
}

void	err_pid(void)
{
	write(2, "Wrong PID Number.\n"
		"If you want use extra PID, "
		"plese check /proc/sys/kernel/pid_max\n", 83);
	exit(1);
}

int	main(int argc, char **argv)
{
	unsigned int	pid;
	unsigned int 	num;
	unsigned int	result;
	int		i;
	int		j;
	if (argc != 3)
		err_usage();
	pid = ft_atoi(argv[1]);
	if (pid > PID_MAX)
		err_pid();
	printf("pid : %d\n", pid);
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			num = argv[2][i];
			result = num >> j-- & 1;
			if (result == 0)
				kill(pid, SIGUSR1);
			else if (result == 1)
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	return (0);
}
