/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:01:14 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/28 16:13:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
/**
 * <signal.h> Library
 * ------------------------------------------------
 * sig_t	signal(int sig, sig_t func);
 * int		sigemptyset(sigset_t *set);
 * int		sigaddset(sigset_t *set, int signo);
 * int		sigaction(int sig, const struct sigaction *restrict act,
 * 					struct sigaction *restrict oact);
 * int		kill(pid_t pid, int sig);
 * ------------------------------------------------
 */

# include <unistd.h>
# include <stdlib.h>

# include "color.h"
# include "../lib/include/libft.h"

# define TRUE		1
# define FALSE		0
# define ENABLE		1
# define DISABLE	0
# define PID_MIN	100
# define PID_MAX	99999

typedef struct s_msg
{
	char			c;
	unsigned int	size;
	int				flag;
	unsigned int	pid;
}					t_msg;


void	err_usage(void);
void	err_pid(void);
int		ft_atoi_mt(const char *str);

#endif
