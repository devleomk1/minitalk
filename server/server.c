/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:53 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/24 21:28:44 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../lib/include/libft.h"
#include "../lib/include/ft_printf.h"
#include <stdio.h>

unsigned int	str;

void	sigusr_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		//비트를 하나씩 밀어서 집어 너허어어어어
		write(1, "1", 2);
		usleep(100);
	}
	else if (signo == SIGUSR2)
	{
		write(1, "0", 2);
		usleep(100);
	}

}

int	main(void)
{
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	ft_printf("./server pid : %d\n", getpid());
	while (1)
	{
		pause();
	}

}
