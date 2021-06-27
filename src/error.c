/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:35:47 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/27 17:30:38 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	err_usage(void)
{
	write(2, YELLOW"Wrong argument! Please check usage.\n"RESET
		"Usage: ./client [server PID] [message]\n", 85);
	exit(1);
}

void	err_pid(void)
{
	write(2, YELLOW"Wrong PID Number.\n"RESET
		"If you want use extra PID, "
		"plese check /proc/sys/kernel/pid_max\n", 92);
	exit(1);
}
