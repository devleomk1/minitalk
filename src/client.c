/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:43 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/27 21:54:10 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	sigusr_handler(int signo)
{
	if(signo == SIGUSR1)
		write(1, "✅ message sent check\n", 24);
}

void	send_msg(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	bit;
	int	client_pid;

	client_pid = getpid();
	ft_printf("./client PID : %d\n", client_pid);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 25)
		{
			if (j < 17)
				bit = client_pid >> j++ & 1;
			else
				bit = str[i] >> (j++ - 17) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(30);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		err_usage();
	pid = ft_atoi_mt(argv[1]);
	if (pid > PID_MAX || pid < PID_MIN)
		err_pid();
	signal(SIGUSR1, sigusr_handler);
	send_msg(pid, argv[2]);
	return (0);
}
