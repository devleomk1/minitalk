/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:53 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/28 15:50:31 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_msg g_msg;

void	init_msg(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	g_msg.flag = TRUE;
	g_msg.pid = 0;
}

void	print_msg(void)
{
	if (g_msg.c == 0)
	{
		kill(g_msg.pid, SIGUSR1);
		g_msg.flag = TRUE;
		g_msg.pid = 0;
	}
	else
		ft_putstr_fd(&g_msg.c, 1);
	g_msg.c = 0;
	g_msg.size = 0;
}

void	sigusr_handler(int signo)
{
	if (g_msg.size < 17 && g_msg.flag == TRUE)
	{
		g_msg.pid += ((signo & 1) << g_msg.size);
		g_msg.size++;
	}
	else if (g_msg.size < 8 && g_msg.flag == FALSE)
	{
		g_msg.c += ((signo & 1) << g_msg.size);
		g_msg.size++;
	}
	if (g_msg.size == 17 && g_msg.flag == TRUE)
	{
		g_msg.flag = FALSE;
		g_msg.size = 0;
	}
	else if (g_msg.size == 8 && g_msg.flag == FALSE)
		print_msg();
}

int		main(void)
{
	if ((signal(SIGUSR1, sigusr_handler) == SIG_ERR) ||
	(signal(SIGUSR2, sigusr_handler) == SIG_ERR))
	{
		write(2, YELLOW"signal error\n"RESET, 23);
		return (0);
	}
	init_msg();
	ft_putstr_fd("./server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
