/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:13:20 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/14 11:11:54 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sigscan(int sig, char *chr, int i, int size)
{
	if (sig == SIGUSR1)
	{
		chr[i] += (1 << size);
		size--;
	}
	else if (sig == SIGUSR2)
	{
		chr[i] += (0 << size);
		size--;
	}
}

static void	message(int sig, siginfo_t *info, void *context)
{
	static char	chr[100000];
	static int	size = 7;
	static int	i = 0;

	(void)context;
	sigscan(sig, chr, i, size);
	kill(info->si_pid, SIGUSR1);
	size--;
	if (size < 0)
	{
		if (chr[i] == '\0')
		{
			i = -1;
			kill(info->si_pid, SIGUSR2);
			ft_printf("%s\n", chr);
			while (++i < 100000)
				chr[i] = '\0';
			i = -1;
		}
		i++;
		size = 7;
	}
}

int	main(void)
{
	struct sigaction	sa_usr;

	ft_printf("PID: %d\n", getpid());
	sa_usr.sa_flags = SA_SIGINFO;
	sa_usr.sa_sigaction = message;
	sigaction(SIGUSR1, &sa_usr, NULL);
	sigaction(SIGUSR2, &sa_usr, NULL);
	while (1)
		;
	return (0);
}
