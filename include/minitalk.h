/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:01:14 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 03:32:54 by jisokang         ###   ########.fr       */
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

# define TRUE	1
# define FALSE	0

#endif
