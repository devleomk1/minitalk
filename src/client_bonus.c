/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:23:02 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/28 19:48:42 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static void	sigusr_handler(int signo)
{
	if (signo == SIGUSR1)
		write(1, "✅ message sent check\n", 24);
}

static void	send_pid(pid_t pid)
{
	int i;
	int bit;
	int	client_pid;

	client_pid = getpid();
	ft_putstr_fd("./client PID : ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putstr_fd("\n", 1);
	i = 0;
	while (i < 17)
	{
		bit = client_pid >> i++ & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

static void	send_null(pid_t pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

static void	send_msg(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			bit = str[i] >> j++ & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		err_usage();
	pid = ft_atoi_mt(argv[1]);
	if (pid > PID_MAX || pid < PID_MIN)
		err_pid();
	signal(SIGUSR1, sigusr_handler);
	send_pid(pid);
	send_msg(pid, argv[2]);
	send_null(pid);
	return (0);
}
