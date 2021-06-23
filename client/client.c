/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:00:43 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 19:50:04 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../lib/include/libft.h"
#include <stdio.h>
// ./client 12345 abcde

void	usage(void)
{
	write(2, "Wrong argument! Please check usage.\nUsage: ./client [server PID] [string]\n", 75);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		c;
	int		arr[8];
	int		len;

	if (argc != 3)
		usage();
	pid = ft_atoi(argv[1]);
	str = argv[2];
	c	= str[0];
	printf("pid : %d\n", pid);
	printf("str : %s\n", str);
	printf("c : %d(", c);
	len = ft_num_tobase(arr, c, 2);
	while (len >= 0)
		printf("%d", arr[len--]);
	printf(")\n");

	return (0);
}
