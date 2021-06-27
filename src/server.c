/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:53 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/27 23:06:47 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>

/**
 * SIGUSR1 = 30 = 0001 1110
 * SIGUSR2 = 31 = 0001 1111
 */

t_msg g_msg;

void	sig_err(void)
{
	write(2, "signal error\n", 14);
	exit(1);
}

void	sigusr_handler(int signo)
{
	if (g_msg.size < 17 && g_msg.flag == TRUE)
	{
		g_msg.cli_pid += ((signo & 1) << g_msg.size);
		//if((signo & 1)) write(1, "1", 2);
		//else write(1, "0", 2);
		g_msg.size++;
	}
	else if (g_msg.size < 8 && g_msg.flag == FALSE)
	{
		g_msg.c += ((signo & 1) << g_msg.size);
		//if((signo & 1)) write(1, "1", 2);
		//else write(1, "0", 2);
		//ft_printf("-->%d<--\n", g_msg.c);
		g_msg.size++;
	}

	if (g_msg.size == 17 && g_msg.flag == TRUE)
	{
		//ft_printf("cli_pid : %d\n", g_msg.cli_pid);
		//ft_printf("bku_pid : %d\n", g_msg.cli_pid_bk);
		g_msg.flag = FALSE;
		g_msg.size = 0;
	}
	if (g_msg.size == 8 && g_msg.flag == FALSE)
	{
		//ft_printf("%d ", g_msg.c);
		if (g_msg.c == 0)
		{
			kill(g_msg.cli_pid, SIGUSR1);
			usleep(50);
			g_msg.flag = TRUE;
		}
		else
			ft_putstr_fd(&g_msg.c, 1);
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int	main(void)
{
	g_msg.flag = TRUE;
	g_msg.cli_pid = 0;
	g_msg.c = 0;
	g_msg.size = 0;
	if((signal(SIGUSR1, sigusr_handler) == SIG_ERR) ||
		(signal(SIGUSR2, sigusr_handler) == SIG_ERR))
		sig_err();
	ft_printf("./server PID : %d\n", getpid());
	while (1)
		pause();
}
