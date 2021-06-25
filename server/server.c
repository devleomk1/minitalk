/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:53 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/25 22:34:29 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../lib/include/libft.h"
#include "../lib/include/ft_printf.h"
#include <stdio.h>

unsigned int	str;

/**
 * SIGUSR0 = 30 = 0001 1110
 * SIGUSR1 = 31 = 0001 1111
 */

void	sigusr_handler(int signo)
{
	int a = 0;
	a << signo & 1;
	if (signo == SIGUSR1)
	{

		write(1, "0", 2);
		usleep(100);
	}
	else if (signo == SIGUSR2)
	{
		write(1, "1", 2);
		usleep(100);
	}

}

int	main(void)
{

	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	ft_printf("./server pid : %d\n", getpid());
	while (1)
		pause();

}
